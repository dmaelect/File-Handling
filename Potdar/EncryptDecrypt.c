#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void writeFile(char mode[]);
char* encryptOrDecryptData(char *data, char operation[]);
void encryptOrDecryptFile(char operation[]);


int main(){
int choice ;
printf("******************************************************************\n");
printf("__________________________________________________________________\n");
printf("\t\tEnter your choice:\n");
printf("__________________________________________________________________\n");
printf("\n\t 1.Create a text file \n\t 2. Create binary file \n\t 3.Read Text File \n\t 4.Read Binary File \n\t 5.Encrypt File \n\t 6.Decrypt file\n\t 7.View Encrypted File\n\t 8.View Decrypted File\n");
printf("******************************************************************\n");
scanf("%d", &choice);
switch(choice){
case 1: 
writeFile("w");
break;
case 2: 
writeFile("wb");
break;
case 3: 
writeFile("r");
break;
case 4: 
writeFile("rb");
break;
case 5 :
encryptOrDecryptFile("encrypt");
break;

case 6: 
encryptOrDecryptFile("decrypt");
break;

case 7:
writeFile("r");
break;
case 8:
writeFile("r");
break;
default:
printf("Please select valid choice");
break;
}

return 0;
}


char* encryptOrDecryptData(char *data, char operation[]){
int i = 0;
int key = data[0];
char ch;
char *str = malloc(100);

if(strcmp(operation,"encrypt") == 0){
key = 4;
}
else if(strcmp(operation,"decrypt") == 0){
key = 4;
} 
for(i = 0; data[i] != '\0'; i++){
        ch = data[i];
        if((ch >= 'a') && (ch <= 'z')){ 
if(strcmp(operation,"decrypt") == 0){
ch = ch - key;
}

            else if(strcmp(operation,"encrypt") == 0){
ch = ch + key;
}
            
if(ch < 'a' && (strcmp(operation,"decrypt") == 0)){
                ch = ch + 'z' - 'a' + 1;
            }
else if(ch > 'z' && (strcmp(operation,"encrypt") == 0)){
ch = ch - 'z' + 'a' - 1; 
}

        }
        
else if(ch >= 'A' && ch <= 'Z'){
if(strcmp(operation,"decrypt") == 0){
ch = ch - key;
}

            else if(strcmp(operation,"encrypt") == 0){
ch = ch + key;
}            
if(ch < 'A' && (strcmp(operation,"decrypt") == 0)){
                ch = ch + 'Z' - 'A' + 1;
            }
else if(ch > 'Z' && (strcmp(operation,"encrypt") == 0)){
ch = ch - 'Z' + 'A' - 1; 
}
        }
str[i] = ch;
    }
return str;
}



void writeFile(char mode[]){
FILE *fp; 
char fileName[40], fileData[100];
char *p, *q, ch;
printf("Enter file name with extension: ");
scanf("%s", fileName);
p = strstr (mode,"b");
  if(p)
strcat(fileName , ".bin");
else
strcat(fileName , ".txt");
fp = fopen(fileName, mode);
if(fp == NULL){
printf("Can not open file");
exit(1); 
}

q = strstr(mode, "w");
if(q){
printf("Enter data : ");
getchar();
fgets (fileData, sizeof fileData, stdin);
fputs(fileData, fp);
}
else{
ch = fgetc(fp);
    while (ch != EOF){
        printf ("%c", ch);
        ch = fgetc(fp);
    }

}
fclose(fp);
}

void encryptOrDecryptFile(char operation[]){
char fileName[40], fileName1[40];
char *result = malloc(1000), ch;
char *data ;
FILE *fp, *fp1;
int i =0;
printf("Enter file name to %s \n",operation);
scanf("%s", fileName);

printf("Enter filename to store results\n");
scanf("%s", fileName1);

strcat(fileName , ".txt");
strcat(fileName1 , ".txt");

fp = fopen(fileName, "r");
fp1 = fopen(fileName1, "w");

if(fp == NULL || fp1 == NULL){
printf("Can not open file");
exit(1); 
}

ch = fgetc(fp);
    while (ch != EOF){
        result[i] = ch;
        ch = fgetc(fp);
i++;
    }
puts(result);


if(strcmp(operation,"encrypt") == 0){
data = encryptOrDecryptData(result,"encrypt");
puts(data);
fputs(data, fp1);
}
else if(strcmp(operation,"decrypt") == 0){
data = encryptOrDecryptData(result,"decrypt");
puts(data);
fputs(data, fp1); 
}
fclose(fp);
fclose(fp1); 
}
