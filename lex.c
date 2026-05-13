#include <stdio.h>
#include <ctype.h>
#include <string.h>


char keywords[20][10] = {
    "if","else","while","for","int","float","char",
    "return","void","do"
};

int isKeyword(char word[])
{
    for(int i=0;i<10;i++)
        if(strcmp(word, keywords[i]) == 0)
            return 1;
    return 0;
}

int isOperator(char ch)
{
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' ||
            ch=='=' || ch=='<' || ch=='>' || ch=='!' );
}

int isDelimiter(char ch)
{
    return (ch==';' || ch==',');
}

int isBrace(char ch)
{
    return (ch=='(' || ch==')' || ch=='{' || ch=='}');
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char input[1000];
    int i=0, j;
    char word[100];

   
    if(argc != 2)
    {
        printf("Usage: %s <inputfile>\n", argv[0]);
        return 1;
    }

    
    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        perror("File Open Error");
        return 1;
    }


    fread(input, sizeof(char), 1000, fp);
    fclose(fp);

   
    while(input[i] != '\0')
    {
   
        if(input[i]==' ' || input[i]=='\t' || input[i]=='\n')
        {
            i++;
            continue;
        }

        if(isalpha(input[i]))
        {
            j = 0;
            while(isalnum(input[i]))
                word[j++] = input[i++];
            word[j] = '\0';

            if(isKeyword(word))
                printf("%s : Keyword\n", word);
            else
                printf("%s : Identifier\n", word);

            continue;
        }

       
        if(isdigit(input[i]))
        {
            j = 0;
            while(isdigit(input[i]))
                word[j++] = input[i++];

            word[j] = '\0';
            printf("%s : Constant\n", word);
            continue;
        }

        
        if(isOperator(input[i]))
        {
            if((input[i]=='<' || input[i]=='>' ||
                input[i]=='=' || input[i]=='!')
                && input[i+1]=='=')
            {
                printf("%c%c : Relational operator\n", input[i], input[i+1]);
                i += 2;
            }
            else if(input[i]=='=')
            {
                printf("%c : Assignment operator\n", input[i]);
                i++;
            }
            else
            {
                printf("%c : Operator\n", input[i]);
                i++;
            }
            continue;
        }

       
        if(isBrace(input[i]))
        {
            if(input[i]=='(') printf("( : O_BRACE\n");
            if(input[i]==')') printf(") : C_BRACE\n");
            if(input[i]=='{') printf("{ : O_BRACE\n");
            if(input[i]=='}') printf("} : C_BRACE\n");
            i++;
            continue;
        }

        
        if(isDelimiter(input[i]))
        {
            printf("%c : Delimiter\n", input[i]);
            i++;
            continue;
        }

        printf("%c : Unknown Symbol\n", input[i]);
        i++;
    }

    return 0;
}
