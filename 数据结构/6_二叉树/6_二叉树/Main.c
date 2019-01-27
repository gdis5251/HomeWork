#include "BinaryTree.h"
#include "CreateTree.h"


void Test()
{
	char *tree = "abd#cef#g";
	int len = strlen(tree);
	Result r = CreateTree(tree, len);

}


int main(void)
{
	Test();

	return 0;
}