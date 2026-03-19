/*
 * camera.h
 *
 *  Created on: Mar 19, 2026
 *      Author: garci
 */


#ifndef CAMERA_H
#define CAMERA_H

#include <stdint.h>

// Initialisation
void camera_init(void);

// Commandes caméra
void camera_reset(void);
void camera_take_photo(void);
void camera_stop_photo(void);
void camera_read_data(void);

// Boucle principale (équivalent loop Arduino)
void camera_process(void);

#endif
