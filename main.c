#include<stdio.h>
#include<time.h>
#include<string.h>
#include<windows.h>

int time_format();
void for_date(char *string);
void for_time(char *string,int format);

int main(){
    char time[50],date[50];
    int format=time_format();
    while(1){
    for_date(date);
    for_time(time,format);
    printf("Current Time: %s\n", time);
    printf("Date: %s\n", date);
    Sleep(1000);
    system("cls");
    }
    return 0;
}

int time_format(){
    int format;
    printf("Choose time format:\n");
    printf("1.24 hour format\n");
    printf("2.12 hour fomrat\n");
    printf("Enter format(1/2)\n");
    scanf("%d",&format);
    return format;
}

void for_date(char *string){
    time_t current_time;
    time(&current_time);
    
    struct tm* time_info;
    time_info=localtime(&current_time);
    strftime(string, 100, "%A %B %d %Y", time_info);
}

void for_time(char *string,int format){
    time_t current_time;
    time(&current_time);
    
    struct tm* time_info;
    time_info=localtime(&current_time);
    if(format==1)
        strftime(string, 50 ,"%H:%M:%S",time_info);
    else 
        strftime(string, 50 ,"%I:%M:%S %p",time_info);   
}
