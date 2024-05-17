#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "gps_logger.h"

int checkGps(const gps_data *data) {
    if (data->latitude > 90000000 || data->longitude < -180000000 || data->latitude < -90000000 ||  data->longitude > 180000000) {
        return 0; // Invalid GPS data
    }
    
    return 1; // Valid GPS data
}

void gps_logger(const char* file_name, const gps_data* data_array, uint32_t entries) {
    FILE *file = fopen(file_name, "a");
    
    if (file == NULL) {
        printf("Error opening file %s\n", file_name);
        return;
    }
    
    uint32_t prev_timestamp = 0;
    for (uint32_t i = 0; i < entries; i++) {
        // Check timestamp
        if (data_array[i].timestamp <= prev_timestamp) {
            printf("Wrong timestamp at entry %u\n", i);
            continue;
        }
        prev_timestamp = data_array[i].timestamp;

        // Validate GPS data
        if (!checkGps(&data_array[i])) {
            printf("Invalid GPS data at entry %u\n", i);
            continue;
        }

        // Calculate checksum
        uint32_t checksum = 0;
        const uint8_t *ptr = (const uint8_t *)&data_array[i];
        size_t size = sizeof(gps_data);
        for (size_t j = 0; j < size; j++) {
            checksum ^= ptr[j];
        }

        // Write data to the file in the specified format
        fprintf(file, "%u,%.6f,%c,%.6f,%c,%d,%u,%u\r\n",
                data_array[i].timestamp, data_array[i].latitude / 1000000.0, data_array[i].latitude_direction,
                data_array[i].longitude / 1000000.0, data_array[i].longitude_direction, data_array[i].altitude,
                data_array[i].num_satellites, checksum);
    }
    
    fclose(file);
}
