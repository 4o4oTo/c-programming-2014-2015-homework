#include <stdio.h>
#include <stdlib.h>
struct stack_t 
{
	int *data;
	int index;
	int size;
};

void stack_init(struct stack_t* s) 
{
	s->size = 20;
	s->index = 0;
	s->data = (int *)malloc(s->size * sizeof(int));
}

void stack_destroy (struct stack_t* s)
{
	free(s->data);
	s->size = 0;
	s->index = 0;
}

void stack_push_back (struct stack_t* s, char value)
{
	s->data[s->index++] = value ;
}
char stack_pop_back(struct stack_t* s)
{
	return s->data[--s->index];
}
int stack_size(struct stack_t s)
{
	return s.index;
}

 
int main ()
{
	struct stack_t s;
	char i,c,p,brackets[20];
	int output = 0;
	
	stack_init(&s);
	printf("Vuvedi niz :");
	scanf("%s",brackets);
	for (c = 0;brackets[c] != '\0';c++)
	{
		if (brackets[c] == '{' || brackets[c] == '[' || brackets[c] == '(')
		{
			stack_push_back(&s,brackets[c]);
		}
	}
			for (i = 0;brackets[i] != '\0';i++)
			{ 
					if (brackets[c] == '{' || brackets[c] == '[' || brackets[c] == '(')
					{
						stack_push_back(&s,brackets[c]);
					}
					//if (stack_size != 0)
					//{
						switch (brackets[i])
						{
							case '}':
								p = stack_pop_back(&s);
								if (p != '{')                   
								{
									//printf("%c-{\n",p);
									output = 1;
								}	
								break;
							case ']':
								p = stack_pop_back(&s);
								if (p != '[')
								{
									//printf("%c-[\n",p);
									output = 1;
								}
								break;
							case ')':
								p = stack_pop_back(&s);
								if (p!= '(')
								{
									//printf("%c-(\n",p);
									output = 1;	
								}
								break;
						}
				
					//}				
			}
	if (output == 0 )
	{
		printf("Valid");
	} 
		else {printf("Invalid\n");}
	stack_destroy(&s);
	return 0;
}
