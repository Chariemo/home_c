#include <stdio.h>
#include "View/Studio_UI.h"
#include "View/Play_UI.h"

int main (void)
{
	int a;
	printf ("0:剧目管理 2:演出厅管理");
	scanf ("%d", &a);
	if ( a == 2)
		Studio_UI_MgtEntry ();

	else if (a == 1 || a == 0)
		Play_UI_MgtEntry (a);
	return 0;
}
