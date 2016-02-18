#include <stdio.h>
#include <unistd.h>

int main() {
    int p[2];
    pipe(p);
    int q[2];
    pipe(q);
    char buf[100];
    int proc_id;

    proc_id = fork();
    if (proc_id == 0) {
        sprintf(buf, "%s", "When is dinner, mom?");
        write(p[1], buf, 100);
        read(q[0], buf, 100);
        printf("Message received from parent was: '%s'\n", buf);
        return 0;
    }

    read(p[0], buf, 100);
    printf("Message received from child was: '%s'\n", buf);

    sprintf(buf, "Dinner is at 5:30. Finish your programming homework.");
    write(q[1], buf, 100);
    
    return 0;
}