#include <stdio.h>
#include "names_st.h"

int main (void)
{
	names condidate;
	get_names (&condidate);
	printf ("Let's welcome ");
	show_names (&condidate);
	printf (" to this program!\n");
	return 0;
}
