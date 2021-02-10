#include <stdio.h>
#include <stdlib.h>     // exit()
#include <unistd.h>     // fork(), setsid(), chdir(), sleep()
#include <sys/types.h>  // pid_t
#include <sys/stat.h>   // umask()
#include <string.h>

int main(int argc, char * argv[])
{
  FILE * fp = NULL;
  pid_t process_id = 0;
  pid_t sid = 0;

  // Create child process
  process_id = fork();

  // Indication of fork() failure
  if(process_id < 0)
  {
    printf("fork failed!\n");
    exit(1);
  }

  // Kill parent process
  if(process_id > 0)
  {
    printf("process_id of child process %d \n", process_id);
    exit(0);  // Return success in exit status
  }

  umask(0);  // Unmask the file mode

  sid = setsid();  // Set new session

  if(sid < 0)
  {
    exit(1);
  }

  chdir("/tmp");  // Change current working directory to root
  close(STDIN_FILENO);   // Close stdin
  close(STDOUT_FILENO);  // Close stdout
  close(STDERR_FILENO);  // Close stderr

  fp = fopen("Log.txt", "w+");

  while(1)
  {
    // Don't block context switches, let the process sleep for some time
    sleep(1);
    fprintf(fp, "Logging info...\n");
    fflush(fp);
  }

  fclose(fp);

  return 0;
}

