#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

char * days[] =
{
  "Sunday"
  ,"Monday"
  ,"Tuesday"
  ,"Wednesday"
  ,"Thursday"
  ,"Friday"
  ,"Saturday"
};

char * months[] =
{
  "January"
  ,"February"
  ,"March"
  ,"April"
  ,"May"
  ,"June"
  ,"July"
  ,"August"
  ,"September"
  ,"October"
  ,"November"
  ,"December"
};

int main()
{
  time_t time_secs;
  struct tm * info;

  while(1)
  {
    time(&time_secs);
    info = localtime(&time_secs);
    printf("%s, %s %d %02d:%02d:%02d\n"
      ,days[info->tm_wday]
      ,months[info->tm_mon]
      ,info->tm_mday
      ,info->tm_hour
      ,info->tm_min
      ,info->tm_sec
    );
    sleep(1);
  }

  return EXIT_SUCCESS;
}

