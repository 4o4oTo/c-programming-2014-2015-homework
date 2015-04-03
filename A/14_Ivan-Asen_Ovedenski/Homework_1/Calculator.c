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

void stack_push_back (struct stack_t* s, int value)
{
	s->data[s->index++] = value ;
}
int stack_pop_back(struct stack_t* s)
{
	return s->data[--s->index];
}
int stack_size(struct stack_t s)
{
	return s.index;
}

int main() 
{
	
	char zadacha[100],ifzero,i;
	int result;
	struct stack_t s;
	stack_init(&s);

	printf("Vuvedi zadacha :");
	scanf("%s",zadacha);
	//printf("%s",zadacha);
	for (i = 0;zadacha[i] != '\n';i++)
	{ 
		if (zadacha[i] >= '0' && zadacha[i] <= '9')
		{
			stack_push_back(&s, zadacha[i]-48);
		}
		
		if (zadacha[i] == '+')
		{
			result = stack_pop_back(&s) + stack_pop_back(&s);
			stack_push_back(&s,result);
		}
		if (zadacha[i] == '-')
		{
			result = stack_pop_back(&s) - stack_pop_back(&s);
			stack_push_back(&s,result);
		}
		if (zadacha[i] == '*')
		{
			result = stack_pop_back(&s) * stack_pop_back(&s);
			stack_push_back(&s,result);
			
		}
		if (zadacha[i] == '/')
		{
			ifzero = stack_pop_back(&s) ;
			if (ifzero != 0)
			{		
				result = ifzero / stack_pop_back(&s);
				stack_push_back(&s,result);
			}
		}
	
	}
	if (stack_size(s) == 0)
	{
		printf("Result :%d \n", stack_pop_back(&s));
	} else printf("Too many arguments !\n");
	stack_destroy(&s);
	
	return 0;
}
