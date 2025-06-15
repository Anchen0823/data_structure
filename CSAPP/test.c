#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
#include <setjmp.h>
#include <errno.h>

extern char **environ;

struct MyResult {
    int code;     // 正常退出码或 -信号号
    int timeout;  // 1 = 超时，0 = 正常
};
// 下面的environ已包含在 "student.h"中
// extern char **environ;


struct MyResult mysystem(const char *command, int timeout_sec) {
//TODO:在这里完成你的代码
    pid_t pid;
    int status;
    struct MyResult result = {0, false};
    
    if (pid == 0) {
        signal(SIGALRM, [](int) {_exit(127);});
        alarm(timeout_sec);
        
        char * argv[] = {"/bin/sh", "-c", (char *)command, NULL};
        execve("/bin/sh", argv, environ);
        
        _exit(127);
    } else {
        if (waitpid(pid, &status, 0) == -1 ) {
            result.code = -1;
            return result;
        }
        
        if (WIFSIGNALED(status) && WTERMSIG(status) == SIGALRM) {
            result.code = 127;
            result.timeout = true;
        } else if (WIFEXITED(status)) {
            result.code = WEXITSTATUS(status);
        } else {
            result.code = -1;
        }
        
        return result;
    }
    

    int main() {
        // Test cases
        struct MyResult r1 = mystream("ls -l", 5);
        printf("Normal command: code=%d, timeout=%d\n", r1.code, r1.timeout);
    
        struct MyResult r2 = mystream("sleep 10", 2);
        printf("Timeout command: code=%d, timeout=%d\n", r2.code, r2.timeout);
    
        return 0;
    }
}