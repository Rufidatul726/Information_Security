#include<stdio.h>
#include<string.h>

char plainLetters[55]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y','Z'};
char encryptedLetters[55]={'q', 'Q', 'w', 'W', 'e', 'E', 'r', 'R', 't', 'T', 'y', 'Y', 'u', 'U', 'i', 'I', 'o', 'O', 'p', 'P', 'a', 'A', 's', 'S', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j', 'J', 'k', 'K', 'l', 'L', 'z', 'Z', 'c', 'C', 'v', 'V', 'b', 'B', 'n', 'N', 'm', 'M'};


int getIndex(char character1){
    for(int i=0;i<53;i++){
        if(plainLetters[i]==character1)return i;
    }
    return -1;
}

int reverseIndex(char character1){
    for(int i=0;i<53;i++){
        if(encryptedLetters[i]==character1)return i;
    }
    return -1;
}

void Encryption(char *input, char *output){
    int index;
    int length=strlen(input);

    for(int i=0;i<length;i++){
            index=getIndex(input[i]);
        if(index!=-1){
            output[i]=encryptedLetters[index];

        }
        else{

            //making non-letters encrypted by changing ascii number within range
            if(input[i]<65)output[i]=-input[i]+64+32;
            else if(input[i]>122)output[i]=127-input[i]+123;
            else output[i]=96-input[i]+91;

        }
    }
    output[length]='\0';
    return;

}

void Decryption(char *input, char *output){
    int index;
    int length=strlen(input);

    for(int i=0;i<length;i++){
            index=reverseIndex(input[i]);
        if(index!=-1){
            output[i]=plainLetters[index];
        }
        else{

            //making non-letters plain by changing reversing again(double reverse
            if(input[i]<65)output[i]=-input[i]+64+32;
            else if(input[i]>122)output[i]=127-input[i]+123;
            else output[i]=96-input[i]+91;
        }
    }
    output[length]='\0';
    return;

}



int main(void){
    char input[1000], encryptedData[1000], decryptedData[1000];
    int i;

    printf("Enter the statement you want to encrypt: ");
    gets(input);

    Encryption(input, encryptedData);
    printf("After Encyption: %s\n", encryptedData);

    Decryption(encryptedData, decryptedData);
    printf("After Decyption: %s\n", decryptedData);


}
