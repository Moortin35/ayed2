/*
  @file weather_utils.h
  @brief defines table helpers methods. These methods operates over multidimensional (year, month, day) array of weather
*/
#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include <stdbool.h>
#include "weather.h"
#include "weather_table.h"

/**
 * @brief Returns the lowest historical temperature.
 * @param[in] a table from which we obtain the temperature *
 */

int lowest_hist_temp(WeatherTable a);


/**
* @brief Modify an array of maximum temperatures for each year *
 * @param a table which will contain the WeatherTable *
 * @details creates and modifies an array, but does not return it, 
 *  that's why it is a procedure *

 */

void highest_hist_temps(WeatherTable a, int array_of_temps[YEARS]);
/**
* @brief similar to the function above, 
    with the difference that the array to be modified is loaded with months
         with maximum precipitation per year. *
 * @param a table which will contain the WeatherTable
 * @details creates and modifies an array, but does not return it, 
 *  that's why it is a procedure *

 */
void array_of_rainfall_month(WeatherTable a, month_t array_of_months[YEARS]);

#endif // _WEATHER_UTILS_H
