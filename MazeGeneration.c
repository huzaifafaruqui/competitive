//Program developed by oculto
#include<stdio.h>

#include<stdlib.h>
#include<time.h>

const int rows=10,cols=10;

struct pair{
	int row,col;
};


pair stack[101];
int tos;
pair next[5],move[5],curr,beg,end;

struct cell{
	int up,right,down,left;
	
	
};

const int total=49;
int visited;
cell maze[rows+1][cols+1];

void init_cells(){

    int i,j;

    //set all walls of each cell in maze
    for (i = 1;i<=rows;i++ ){
	
        for(j=1;j<=cols;j++)
     {
		      maze[i][j].up =1;
            maze[i][j].down =1;
            maze[i][j].right =1;
            maze[i][j].left =1;
    }
    
}
    //index for top of cell stack 
    tos = 0;

    //array of single step movements between cells
    move[1].row = -1;// north
    move[1].col = 0;
    move[2].row = 0 ;  // east
    move[2].col =  1;
    move[3].row =  1 ;  // south
    move[3].col =  0;
    move[4].row =  0 ;  // west
    move[4].col = -1;

}

void print_maze()
{

    int i,j,k;

    for(i=1;i<=rows;i++)
        for(k=1;k<=2;k++){
		
            for(j=1;j<=cols;j++) {
                if (k == 1){
			
                    if (maze[i][j].up) 
                        printf ("----");
                    else
                        printf("    ");
                    
                    if (j ==cols)
                        printf(" ");
                    
                }
				else if (k == 2) {
					if(beg.row==i&&beg.col==j)
					{
					
					printf("S   ");
	
					}
					
					else if(end.row==i&&end.col==j)
					{
					if (maze[i][j].left)
					printf("| E ");
					else
					printf(" E  ");
					
				   }
					else{
					
                    if (maze[i][j].left) 
                        printf("|   ");
                    else
                        printf("    ");
                    }
						//if(maze[i][j].right)
                        //printf("|");
                        //else
                        //printf(" ");
                    
                    if (j == cols) 
                        printf("|");
                    
                    }
        }
            printf("\n");
    }
    
    for(j=1;j<=cols;j++)
        printf("----");
    
     printf(" \n");
    
}


main()
{  time_t t;
	srand((unsigned) time(&t));
	init_cells();
	int i,j,r,c;
	curr.row=rand()%(rows+1);
	if(curr.row==0)
	curr.row++;
	srand((unsigned) time(&t));
	curr.col=1;
	beg=curr;
	visited=1;
	while(visited<total)
	{
		j=0;
	
		srand((unsigned) time(&t));
		for(i=1;i<=4;i++)
		{
			r=curr.row+move[i].row;
			c=curr.col+move[i].col;
			if(r>0&&r<=rows&&c>0&&c<=cols)
			{
				if(maze[r][c].up &&maze[r][c].down&&maze[r][c].right&&maze[r][c].left)
				{
					j++;
					next[j].row=r;
					next[j].col=c;
					
				}
			}
		}
		if(j>=1)
		{  srand((unsigned) time(&t));
			i=rand()%j+1;
			if(next[i].row-curr.row==0)
			{
				r=next[i].row;
				if(next[i].col>curr.col)
				{
					c=curr.col;
					maze[r][c].right=0;
					c=next[i].col;
					maze[r][c].left=0;
					
				}
				else
				{
					c=curr.col;
					maze[r][c].left=0;
					c=next[i].col;
					maze[r][c].right=0;
					
				}
			}
			else
			{
				 c= next[i].col;
                if (next[i].row > curr.row) {
				
                    //move south
                    r = curr.row;
                    maze[r][c].down =0;
                    r = next[i].row;
                    maze[r][c].up = 0;
                }
				else {
				                               
                   // move north
                    r = curr.row;
                    maze[r][c].up = 0;
                    r = next[i].row;
                    maze[r][c].down = 0;
                }
            }
            tos++;
            stack[tos].row = curr.row;
            stack[tos].col = curr.col;
            //make the new cell current cell
            curr.row = next[i].row;
            curr.col = next[i].col;
            //add 1 to visited cell count
            visited++;
            
			}
			
			else
			{
			 //reached dead end, backtrack
            // pop the most recent cell from the cell stack
            //and make it the current cell
            curr.row = stack[tos].row;
            curr.col = stack[tos].col;
            tos--;
			}
			//printf("%d %d %d\n\n",visited,curr.row,curr.col);
		}
	end=curr;
	printf("\n\n\n");
	print_maze();
	printf("\n");
	printf("\n");
	printf("\n");
	return 0;
}
