/*
 * camera.c
 *
 *  Created on: Mar 19, 2026
 *      Author: garci
 */


#include "camera.h"
#include <stdio.h>

// ===== Dépendances à adapter selon ton hardware =====
// Ces fonctions doivent être implémentées ailleurs
extern void serial_write_byte(uint8_t byte);
extern int serial_available(void);
extern uint8_t serial_read_byte(void);
extern void delay_ms(int ms);

// ===== Variables internes =====
static uint8_t EndFlag = 0;
static uint16_t addr = 0;

// ===== Fonctions internes =====
static void send_reset_cmd(void);
static void send_take_photo_cmd(void);
static void send_read_data_cmd(void);
static void stop_take_photo_cmd(void);

// ===== API publique =====

void camera_init(void)
{
    EndFlag = 0;
    addr = 0;
}

void camera_process(void)
{
    uint8_t incomingbyte;
    uint8_t buffer[32];
    uint8_t j, k, count;

    send_reset_cmd();
    delay_ms(4000);

    send_take_photo_cmd();

    // Flush buffer
    while (serial_available() > 0)
    {
        serial_read_byte();
    }

    while (!EndFlag)
    {
        j = 0;
        k = 0;
        count = 0;

        send_read_data_cmd();
        delay_ms(25);

        while (serial_available() > 0)
        {
            incomingbyte = serial_read_byte();
            k++;

            if ((k > 5) && (j < 32) && (!EndFlag))
            {
                buffer[j] = incomingbyte;

                if ((buffer[j - 1] == 0xFF) && (buffer[j] == 0xD9))
                {
                    EndFlag = 1;
                }

                j++;
                count++;
            }
        }

        // Affichage HEX (équivalent Serial.print)
        for (j = 0; j < count; j++)
        {
            if (buffer[j] < 0x10)
                printf("0");

            printf("%X ", buffer[j]);
        }
        printf("\n");
    }

    while (1); // stop
}

// ===== Implémentation commandes =====

static void send_reset_cmd(void)
{
    serial_write_byte(0x56);
    serial_write_byte(0x00);
    serial_write_byte(0x26);
    serial_write_byte(0x00);
}

static void send_take_photo_cmd(void)
{
    serial_write_byte(0x56);
    serial_write_byte(0x00);
    serial_write_byte(0x36);
    serial_write_byte(0x01);
    serial_write_byte(0x00);
}

static void send_read_data_cmd(void)
{
    uint8_t MH = addr / 0x100;
    uint8_t ML = addr % 0x100;

    serial_write_byte(0x56);
    serial_write_byte(0x00);
    serial_write_byte(0x32);
    serial_write_byte(0x0c);
    serial_write_byte(0x00);
    serial_write_byte(0x0a);
    serial_write_byte(0x00);
    serial_write_byte(0x00);
    serial_write_byte(MH);
    serial_write_byte(ML);
    serial_write_byte(0x00);
    serial_write_byte(0x00);
    serial_write_byte(0x00);
    serial_write_byte(0x20);
    serial_write_byte(0x00);
    serial_write_byte(0x0a);

    addr += 0x20;
}

static void stop_take_photo_cmd(void)
{
    serial_write_byte(0x56);
    serial_write_byte(0x00);
    serial_write_byte(0x36);
    serial_write_byte(0x01);
    serial_write_byte(0x03);
}
