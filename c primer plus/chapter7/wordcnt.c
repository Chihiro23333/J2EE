//统计字符数,单词数,行数
#include <stdio.h>
#include <ctype.h>
#define STOP '|'

int main(void)
{

    int char_num = 0;
    int word_num = 0;
    int line_num = 0;
    int p_line_num = 0;
    int inword = 0;
    char ch;
    char pre = '\n';

    printf("enter str to anaylysize:\n");
    while ((ch = getchar()) != STOP)
    {   
        char_num++;
        if(ch == '\n')
            line_num++;
        
        if(!isspace(ch) && !inword)
        {
            word_num++;
            inword = 1;
        }

        if(isspace(ch) && inword)
            inword = 0;

        pre = ch;
    }
    
    if(pre == '\n')
        p_line_num = 1;

    printf("char_num=%d,word_num=%d,line_num=%d,p_line_num=%d",char_num, word_num, line_num, p_line_num);

    return 0;
}