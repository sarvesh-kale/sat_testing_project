/* Regular Expression matching in C.  This is a short example that shows
the basic principles. reg2.c shows match and capture. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>

int main () {

        char reginald[81];
        char millie[81];
        regex_t emma;
        int status;

        /* Read in and compile a regular expression */

        printf("Please give test expression: ");
        fgets(reginald,80,stdin);
        reginald[strlen(reginald)-1] = '\0';

        /* Let's use extended regular expresssions, and let's just go for "yes / no" */

        status = regcomp(&emma,reginald,REG_EXTENDED|REG_NOSUB);
        printf("Validity of regex (0 => OK): %d\n",status);

        /* Leave program if regex is faulty */
        /* we could use regerror to decode the error ... */
        if (status) return 1;

        while (1) {

                /* Loop until an empty line id given */

                printf("Please give test string: ");
                fgets(millie,80,stdin);
                millie[strlen(millie)-1] = '\0';
                if (strlen(millie) < 1) break;

                status = regexec(&emma,millie,(size_t)0,NULL,0);
                printf("Matched (0 => Yes):  %d\n",status);

                }

        return 0;

        }

