void *control_rgb(void *arg);
void *control_fan(void *arg);
void *control_dc(void *arg);

void exit_dc(int signo);
void exit_fan(int signo);
void exit_rgb(int signo);
