#include "global.h"
#include "util.h"
#include "cminus.tab.h"

    FILE *output;
    output = fopen("output_analysis.txt", "a");
    fprintf(output, "/* =========================== IMPRESSAO DA ARVORE SINTATICA ============================= */");
    fclose(output);

TreeNode * newStmtNode(StmtKind kind){

	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
    	int i;

	for (i=0;i<MAXCHILDREN;i++)
		t->child[i] = NULL;
	t->sibling = NULL;
	t->nodekind = Stmt;
	t->kind.stmt = kind;
	t->lineno = lineno;

    return t;
}

TreeNode * newExpNode(ExpKind kind){

	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
    int i;

	for (i=0;i<MAXCHILDREN;i++)
		t->child[i] = NULL;
	t->sibling = NULL;
	t->nodekind = Exp;
	t->kind.exp = kind;
	t->lineno = lineno;

    return t;
}

TreeNode * newDeclNode(DeclKind kind){

	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
    int i;

	for (i=0;i<MAXCHILDREN;i++)
		t->child[i] = NULL;
	t->sibling = NULL;
	t->nodekind = Decl;
	t->kind.decl = kind;
	t->lineno = lineno;

   return t;
}


char * copyString(char * s)
{ int n;
  char * t;
  if (s==NULL) return NULL;
  n = strlen(s)+1;
  t = malloc(n);
  if (t==NULL)
    printf("Sem memoria na linha %d\n",lineno);
  else strcpy(t,s);
  return t;
}


/* =========================== IMPRESSAO DA ARVORE SINTATICA ============================= */



static indentno = 0;


#define INDENT indentno+=1
#define UNINDENT indentno-=1


static void printSpaces(void)
{ int i;
  for (i=0;i<indentno;i++){
    FILE *output;
    output = fopen("output_analysis.txt", "a");
    fprintf(output, "-->");
    fclose(output);
    printf("-->");
    }
}



void printTree( TreeNode * tree ){
    int i;
    INDENT;
    while (tree != NULL) {
        printSpaces();
        FILE *output;
        output = fopen("output_analysis.txt", "a");
        fprintf(output, " ");
        fclose(output);
        printf(" ");
        if (tree->nodekind==Stmt){
            switch (tree->kind.stmt){
                case If:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "if\n");
                    fclose(output);
                    printf("if\n");
                    break;
                case Iter:

                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "while\n");
                    fclose(output);

                    printf("while\n");
                    break;
                case Attr:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "=\n");
                    fclose(output);

                    printf("=\n");
                    break;
                case Return:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "return\n");
                    fclose(output);

                    printf("return\n");
                    break;
                case Ativacao:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "%s\n", tree->attr.name);
                    fclose(output);

                    printf("%s\n",tree->attr.name);
                    break;
                default:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "tipo desconhecido\n");
                    fclose(output);

                    printf("tipo desconhecido\n");
                    break;
            }
        } else if (tree->nodekind==Exp){
            switch (tree->kind.exp){
                case Const:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "%d\n",tree->attr.val);
                    fclose(output);

                    printf("%d\n",tree->attr.val);
                    break;
                case Id:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "%s\n",tree->attr.name);
                    fclose(output);

                    printf("%s\n",tree->attr.name);
                    break;
                case Op:
			switch(tree->attr.op){
				case ATTR:
				FILE *output;
                output = fopen("output_analysis.txt", "a");
                fprintf(output, "=");
                fclose(output);

				printf("=");
				break;

				case LET:
				FILE *output;
                output = fopen("output_analysis.txt", "a");
                fprintf(output, "<=");
                fclose(output);

				printf("<=");
				break;

				case LT:
				FILE *output;
                output = fopen("output_analysis.txt", "a");
                fprintf(output, "<");
                fclose(output);

				printf("<");
				break;

				case HET:
				FILE *output;
                output = fopen("output_analysis.txt", "a");
                fprintf(output, ">=");
                fclose(output);

				printf(">=");
				break;

				case HT:
				FILE *output;
                output = fopen("output_analysis.txt", "a");
                fprintf(output, ">");
                fclose(output);

				printf(">");
				break;

				case EQUAL:
				FILE *output;
                output = fopen("output_analysis.txt", "a");
                fprintf(output, "==");
                fclose(output);

				printf("==");
				break;

				case DIFF:
				FILE *output;
                output = fopen("output_analysis.txt", "a");
                fprintf(output, "!=");
                fclose(output);

				printf("!=");
				break;

				case PLUS:
				FILE *output;
                output = fopen("output_analysis.txt", "a");
                fprintf(output, "+");
                fclose(output);

				printf("+");
				break;

				case MINUS:
				FILE *output;
                output = fopen("output_analysis.txt", "a");
                fprintf(output, "-");
                fclose(output);

				printf("-");
				break;

				case TIMES:
				FILE *output;
                output = fopen("output_analysis.txt", "a");
                fprintf(output, "*");
                fclose(output);

				printf("*");
				break;

				case OVER:
				FILE *output;
                output = fopen("output_analysis.txt", "a");
                fprintf(output, "/");
                fclose(output);

				printf("/");
				break;
			}

		    FILE *output;
            output = fopen("output_analysis.txt", "a");
            fprintf(output, "\n");
            fclose(output);


		    printf("\n");
                    break;
                default:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "tipo desconhecido\n");
                    fclose(output);

                    printf("tipo desconhecido\n");
                    break;
            }
        } else if (tree->nodekind==Decl){
            switch (tree->kind.decl){
                case Var:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "int %s\n",tree->attr.name);
                    fclose(output);

                    printf("int %s\n",tree->attr.name);
                    break;
                case Fun:
			switch(tree->type){
				case Void:
					FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "void ");
                    fclose(output);

					printf("void ");
					break;
				case Int:
					FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "int ");
                    fclose(output);

					printf("int ");
					break;
			}

                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "%s\n",tree->attr.name);
                    fclose(output);

                    printf("%s\n",tree->attr.name);
                    break;
                case Param:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "int %s\n",tree->attr.name);
                    fclose(output);

                    printf("int %s\n",tree->attr.name);
                    break;
                default:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "tipo desconhecido\n");
                    fclose(output);

                    printf("tipo desconhecido\n");
                    break;
            }
        } else {

            FILE *output;
            output = fopen("output_analysis.txt", "a");
            fprintf(output, "tipo desconhecido\n");
            fclose(output);

            printf("tipo desconhecido\n");
        }

        for (i=0;i<MAXCHILDREN;i++)
            printTree(tree->child[i]);

        tree = tree->sibling;
    }

    UNINDENT;
}
void imprime2(TreeNode * tree);
void preOrdem(TreeNode * t){

    int i;
    while(t!=NULL){
        /*
         Executa algo aqui

        */

        for(i=0;i<MAXCHILDREN;i++)
            preOrdem(t->child[i]);

        t=t->sibling;
    }
}

void inOrdem(TreeNode * t){

    while(t!=NULL){

        inOrdem(t->child[0]);

        // Executa algo aqui

        imprime2(t);

        inOrdem(t->child[1]);

        // Executa algo aqui

        imprime2(t);

        inOrdem(t->child[2]);


        t=t->sibling;
    }
}

void imprime2(TreeNode * tree){
    if (tree->nodekind==Stmt){
            switch (tree->kind.stmt){
                case If:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "if\n"););
                    fclose(output);

                    printf("if\n");
                    break;
                case Iter:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "while\n");
                    fclose(output);

                    printf("while\n");
                    break;
                case Attr:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "=\n");
                    fclose(output);

                    printf("=\n");
                    break;
                case Return:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "return\n");
                    fclose(output);

                    printf("return\n");
                    break;
                case Ativacao:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "%s\n",tree->attr.name);
                    fclose(output);

                    printf("%s\n",tree->attr.name);
                    break;
                default:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "tipo desconhecido\n");
                    fclose(output);

                    printf("tipo desconhecido\n");
                    break;
            }
        } else if (tree->nodekind==Exp){
            switch (tree->kind.exp){
                case Const:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "%d\n",tree->attr.val);
                    fclose(output);

                    printf("%d\n",tree->attr.val);
                    break;
                case Id:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "%s\n",tree->attr.name);
                    fclose(output);

                    printf("%s\n",tree->attr.name);
                    break;
                case Op:
			switch(tree->attr.op){
				case ATTR:
				FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "=");
                    fclose(output);

				printf("=");
				break;

				case LET:
				FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "<=");
                    fclose(output);

				printf("<=");
				break;

				case LT:
				    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "<");
                    fclose(output);

				printf("<");
				break;

				case HET:
				    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, ">=");
                    fclose(output);


				printf(">=");
				break;

				case HT:
				    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, ">");
                    fclose(output);


				printf(">");
				break;

				case EQUAL:
				    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "==");
                    fclose(output);

				printf("==");
				break;

				case DIFF:
				    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "!=");
                    fclose(output);

				printf("!=");
				break;

				case PLUS:
				    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "+");
                    fclose(output);

				printf("+");
				break;

				case MINUS:
				    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "-");
                    fclose(output);

				printf("-");
				break;

				case TIMES:
				    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "*");
                    fclose(output);


				printf("*");
				break;

				case OVER:
				    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "/");
                    fclose(output);

				printf("/");
				break;
			}

		    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "\n");
                    fclose(output);

		    printf("\n");
                    break;
                default:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "tipo desconhecido\n");
                    fclose(output);


                    printf("tipo desconhecido\n");
                    break;
            }
        } else if (tree->nodekind==Decl){
            switch (tree->kind.decl){
                case Var:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "int %s\n",tree->attr.name);
                    fclose(output);

                    printf("int %s\n",tree->attr.name);
                    break;
                case Fun:
			switch(tree->type){
				case Void:
					FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "void ");
                    fclose(output);

					printf("void ");
					break;
				case Int:
					FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "int ");
                    fclose(output);

					printf("int ");
					break;
			}
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "%s\n",tree->attr.name);
                    fclose(output);

                    printf("%s\n",tree->attr.name);
                    break;
                case Param:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "int %s\n",tree->attr.name);
                    fclose(output);

                    printf("int %s\n",tree->attr.name);
                    break;
                default:
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "tipo desconhecido\n");
                    fclose(output);

                    printf("tipo desconhecido\n");
                    break;
            }
        } else {
                    FILE *output;
                    output = fopen("output_analysis.txt", "a");
                    fprintf(output, "tipo desconhecido\n");
                    fclose(output);

            printf("tipo desconhecido\n");
        }
}
