#ifndef GPS_LOGGER_H
#define GPS_LOGGER_H

#include <stdint.h>

// Define the structure for GPS data
typedef struct {
    uint32_t timestamp;
    int32_t latitude;
    char latitude_direction;
    int32_t longitude;
    char longitude_direction;
    int16_t altitude;
    uint8_t num_satellites;
} gps_data;

// Function to validate GPS data
int validate_gps_data(const gps_data *data);

// Function to calculate the checksum
uint32_t calculate_checksum(const gps_data *data);

// Function to log GPS data to a file
void gps_logger(const char* file_name, const gps_data* data_array, uint32_t entries);

#endif /* GPS_LOGGER_H */
