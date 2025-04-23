#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "weather_table.h"
#include "weather.h"


int lowest_hist_temp(WeatherTable a){
    int lowest_historical_temp;
    for (unsigned int year = 0u; year < YEARS; ++year) {
        lowest_historical_temp = a[year][january][0]._min_temp;
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (a[year][month][day]._min_temp < lowest_historical_temp){
                    lowest_historical_temp = a[year][month][day]._min_temp;
                }
            }
        }
    }
    return lowest_historical_temp;
}

void highest_hist_temps(WeatherTable a, int array_of_temps[YEARS]){

    int year_TempMax;
    for (unsigned int year = 0u; year < YEARS; ++year) {
        year_TempMax = a[year][january][0]._max_temp;
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (a[year][month][day]._max_temp > year_TempMax){
                    year_TempMax = a[year][month][day]._max_temp;
                }
            }
        }
        array_of_temps[year] = year_TempMax;
    }
    //Se puede optimizar implementando el print en el for de arriba.
    for (unsigned int year = 0; year < YEARS; year++) {
        printf("la mayor temperatura máxima del año %d: %d \n",1980+year, array_of_temps[year]);       
    }

}

month_t promedio_precs(WeatherTable a, int year){
    month_t res;
    float average;
    float max_average = 0;
    for (month_t month = january; month <= december; month++){
        for (int day = 0; day < DAYS; day++){
            average = average + a[year][month][day]._rainfall;
        }
        average = average / DAYS;
        if (average > max_average){
            max_average = average;
            res = month;
        }
    }
    return res;
}

void array_of_rainfall_month(WeatherTable a, month_t array_of_months[YEARS]){
    month_t mesPrec;
    for (int i = 0; i < YEARS; i++){
        mesPrec = promedio_precs(a, i);
        array_of_months[i] = mesPrec;
    }
    for (unsigned int year = 0; year < YEARS; year++) {
        printf("El mes con mayor precipitaciones del año %d es: %d \n",1980+year, array_of_months[year]);       
    }
}

