
#include "imgUtils.c"
#include <string.h>

int check=0;
// This lets the driver code override the
// image size if it needs to. Make sure you
// don't hard-code these values anywhere!
#ifndef SIZEX
#define SIZEX 512
#define SIZEY 512
#endif  // !SIZEX



typedef struct cmdnode 
{
	char cmd[10];
	int val;
	struct cmdnode *next;
	struct cmdnode *loop_head;
	

} CmdNode;


void insertCommandLoop(CmdNode *loop, CmdNode *new_node)
{
	struct cmdnode *p = NULL;
	if (loop->loop_head==NULL) 
	{
		loop->loop_head = new_node;
		return;
	}
	
	p= loop->loop_head;
	while(p->next!=NULL)
	{
		// printf("%s %d\n", p->cmd, p->val);
		// printf("%s %d\n", new_node->cmd, new_node->val);
		p=p->next;
		
	}
	
	p->next = new_node;
}

////////////////////////////////////////////////////////////////////////////////////

CmdNode *newCmdNode(char cmd[10], int val) {
   CmdNode *new_node = NULL;
   new_node = (CmdNode *)calloc(1,sizeof(CmdNode));
   // int check=0;
   if (strcmp (cmd,"penup") !=0 && strcmp (cmd,"pendown") !=0 && strcmp (cmd,"right") !=0 && strcmp (cmd,"left") !=0 &&
   strcmp (cmd,"forward") !=0 && strcmp (cmd,"backward") !=0 && strcmp (cmd,"colour") !=0 && strcmp (cmd,"loop") !=0 )
   {
	   printf("Invalid command.\n");
	   return NULL;
	}
   strcpy(new_node->cmd,cmd);
   new_node->val=val;
   new_node->next=NULL;
   
   return new_node;
}



////////////////////////////////////////////////////////////////////////////////////

void printCommandList(CmdNode *head) {
  
   if (head==NULL){printf("Command list is empty\n");}
   CmdNode *p= NULL;
   p=head;
   int count=0;
   while(p!=NULL)
   {
	   if ( strcmp(p->cmd,"penup") == 0 || strcmp(p->cmd,"pendown") == 0 || strcmp(p->cmd,"right") == 0 || 
	   strcmp(p->cmd,"left") ==0)
	   {
		   printf("%3d: %s\n", count, p->cmd);
	   }
	   else if (strcmp(p->cmd,"forward") == 0 || strcmp(p->cmd,"backward") == 0 || strcmp(p->cmd,"colour") == 0)
	   {
		   printf("%3d: %s %d\n", count, p->cmd, p->val);
	   }
	   
	   else if (strcmp(p->cmd,"loop") == 0)
	   {
		   printf("%3d: %s %d\n", count, p->cmd, p->val);
		   
		   struct cmdnode *p1 =NULL;
		   
		   if (p->loop_head==NULL){printf("Loop Command list is empty\n");}
		   
		   p1 = p->loop_head;
		   
		   while(p1!=NULL)
		   {
			   count++;
		   
				if ( strcmp(p1->cmd,"penup") == 0 || strcmp(p1->cmd,"pendown") == 0 || strcmp(p1->cmd,"right") == 0 || 
				strcmp(p1->cmd,"left") ==0)
			   {
				   printf("%3d:   %s\n", count, p1->cmd);
			   }
			   else if (strcmp(p1->cmd,"forward") == 0 || strcmp(p1->cmd,"backward") == 0 || strcmp(p1->cmd,"colour") == 0)
			   {
				   printf("%3d:   %s %d\n", count, p1->cmd, p1->val);
				
			   }
			   else{;}
			   p1=p1->next;
			   
		   }
	   }
	   
	   else{;}
	   
	   p=p->next;
	   count++;
	   
   }
  return;
}

////////////////////////////////////////////////////////////////////////////////////

void queryByCommand(CmdNode *head, char cmd[10]) {
  /* This function looks for commands in the linked list that
   * match the input query. It prints them out in the same format
   * as the printCommandList() function.
   * 
   * Make sure that the line number of the commands that match
   * is the same as the line number that would be printed by
   * the printCommandList() function.
   * 
   * -----------------------------------------------------------
   * 
   * For instance, if your printCommandList function outputs
   * 
   *    0: penup
   *    1: forward 200
   *    2: right
   *    3: forward 50
   * 
   * Then, if this function is called with the same list and
   *  cmd = "forward", then your output here should be
   * 
   *    1: forward 200
   *    3: forward 50
   */

   
   CmdNode *p= NULL;
   p=head;
   int count=0;
   while(p!=NULL)
   {
	   if (strcmp(p->cmd,cmd) == 0)
	   {
		   if ( strcmp(p->cmd,"penup") == 0 || strcmp(p->cmd,"pendown") == 0 || strcmp(p->cmd,"right") == 0 || 
		   strcmp(p->cmd,"left") ==0) 
		   {
			   printf("%3d: %s\n", count, p->cmd);
		   }
		   else if (strcmp(p->cmd,"forward") == 0 || strcmp(p->cmd,"backward") == 0 || strcmp(p->cmd,"colour") == 0) 
		   {
			   printf("%3d: %s %d\n", count, p->cmd, p->val);
		   }
		   
		   else{;}
	   }
	   
	   else if (strcmp(p->cmd, "loop") == 0)
	   {
		   struct cmdnode *p1 =NULL;
		   p1 = p->loop_head;
		   
		   while(p1!=NULL)
		   {
			   count++;
			   if (strcmp(p1->cmd,cmd) == 0)
				{
			   
				   if ( strcmp(p1->cmd,"penup") == 0 || strcmp(p1->cmd,"pendown") == 0 || strcmp(p1->cmd,"right") == 0 || 
				   strcmp(p1->cmd,"left") ==0) 
				   {
					   printf("%3d: %s\n", count, p1->cmd);
				   }
				   else if (strcmp(p1->cmd,"forward") == 0 || strcmp(p1->cmd,"backward") == 0 || strcmp(p1->cmd,"colour") == 0) 
				   {
					   printf("%3d: %s %d\n", count, p1->cmd, p1->val);
				   }
			   
					else{;}
				}
			   p1=p1->next;
		   }
		   
		   
	   }
	   else{;}
	   
	   p=p->next;
	   count++;
	   
   }
   
   

  return;
}

////////////////////////////////////////////////////////////////////////////////////

int countCommands(CmdNode *head) {
  /* This function counts and returns the length of the 
   * linked list. It requires list traversal.
   */

   CmdNode *p= NULL;
   p=head;
   int count=0;
   
   while(p!=NULL)
   {
	   count++;
	   if (strcmp(p->cmd,"loop") == 0)
	   {
		   
		   struct cmdnode *p1 =NULL;
		   p1 = p->loop_head;
		   
		   while(p1!=NULL)
		   {
			   count++; 
			   p1=p1->next;
		   }
	   }
	   p=p->next;
   }

  return count;
}

////////////////////////////////////////////////////////////////////////////////////

CmdNode *insertCommand(CmdNode *head, CmdNode *new_CmdNode) {
  /* This function inserts the node new_CmdNode *at the tail* 
   * of the linked list. (You are adding a command at the end).
   * 
   * If head == NULL, then the linked list is still empty.
   * 
   * It returns a pointer to the head of the linked list with
   * the new node added into it.
   */

   CmdNode *p= NULL;
   if (head==NULL)
   {
	   return new_CmdNode;
   }
   
   p=head;
   
   while(p->next!=NULL)
   {
	   p=p->next;
   }
   
   p->next=new_CmdNode;
   

  return head;
}


////////////////////////////////////////////////////////////////////////////////////

CmdNode *deleteCommandList(CmdNode *head) {
  /* This function deletes the linked list of commands, 
   * releasing all the memory allocated to the nodes in 
   * the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   */

   
   head=NULL;
   
   
   CmdNode *p= NULL;
   CmdNode *q= NULL;
   p=head;
   
   while (p!=NULL)
   {
	   if (strcmp(p->cmd, "loop") == 0)
	   {
		   struct cmdnode *p1 =NULL;
		   struct cmdnode *q1 =NULL;
		   
		   p1 = p->loop_head;
		   
		   while(p1!=NULL)
		   {
			   q1=p1->next;
			   free(p);
			   p1=q1;
	
		   }
	   }		   
	   
	   
	   q=p->next;
	   free(p);
	   p=q;
	   
   }
   

  return NULL;
}

////////////////////////////////////////////////////////////////////////////////////

void run(Image *im, CmdNode *head, int *endX, int *endY) {
  /* This function runs the list of commands to move the turtle around
   * and draw the image, and returns the final (x,y) position of the turtle
   * in the locations pointed to by endX and endY.
   * -------------------------------------------------------------------
   * 
   * NOTE: In the image we work with, the top-left pixel is (0,0),
   *       x increases from 0 as you go right, up till SIZEX-1
   *       y increases from 0 as you go down, up till SIZEY-1
   * 
   *                 (0,0)                  (SIZEX-1, 0)
   *                   x------------------------x
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   |          IMAGE         |
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   x------------------------x
   *              (0, SIZEY-1)            (SIZEX-1, SIZEY-1)
   * 
   *  The image is in grayscale (black and white), so the colours are
   *  numbers from [0-255] where 0 is black, 255 is white, and the values
   *  in between are varying levels of gray.
   * 
   *  You need to understand how the (x,y) values are stored so you know
   *  how they should be updated when you move (down means y increases, etc).
   *  You do not need to use the 'im' variable for anything other than 
   *  passing it into the drawLine() function described below.
   * 
   * --------------------------------------------------------------------
   * 
   * Here's the setup - There is a turtle with a pen, that walks along 
   * the image. When the pen is down (on the paper), it draws a line 
   * along the path that it is walking along. (If you want to play 
   * around with this, consider looking at the turtle library in python!)
   * 
   * The turtle initially starts at pixel (0, 0) [at the top left], 
   * facing right (in the positive x direction). The pen starts off
   * as down, with the default colour being black (0).
   * 
   * You need to go through the linked list of commands and 'run' them.
   * This means that you need to keep track of the current position of
   * the turtle, the direction it is facing, and the colour of the pen.
   * As you go through each command, you must update these values 
   * according to the specification given below for each one:
   * 
   *  - penup          : Put the pen up (stop drawing)
   *  - pendown        : Put the pen down (start / continue drawing)
   *  - colour <val>   : Draw lines in colour <val> from now on
   *  - forward <val>  : Move the turtle forward <val> steps (pixels) 
   *                     in the direction it is facing.
   *  - backward <val> : Same as above, except move backwards
   *  - right          : Turn the turtle to the right (clockwise) by 90 degrees
   *  - left           : Turn the turtle to the left (counter-clockwise) by 90 degrees
   * 
   * When you see a forward / backward command and move the turtle, 
   * you need to first check if the pen is currently down (and drawing),
   * and if so, you need to call the drawLine() function (look below)
   * with the position of the turtle before and after you have performed
   * the move, and the current colour of the pen.
   * 
   * When you are done with all the commands, store the final x and y 
   * positions of the turtle in the locations pointed to by endX and endY. 
   * 
   * ------------------------------------------------------------------   * 
   * 
   * For instance, if the commands are:
   *   
   *    0: penup
   *    1: forward 10
   *    2: right
   *    3: pendown
   *    4: forward 20
   * 
   * Then here's what we should be keeping track of with each command:
   *  
   *    0: The pen is lifted up. We will not draw any lines when moving.
   *    1: The turtle moves forward from (0,0) to the position (10, 0) 
   *    2: The turtle turns clockwise. It's now facing the bottom.
   *    3: The pen is now down, we will draw lines for any moves from now.
   *    4: The turtle moves forward from (10,0) to (10, 20). Since the
   *       pen is down, we are going to have to draw a line. We will make
   *       this function all: 
   *                       
   *          drawLine(im, 10, 0, 10, 20, 0);   // Default colour 0, unchanged.
   * 
   *    Now, since the commands are done, we would store the final 
   *    position of the turtle, (10, 20) in the corresponding variables.
   *    *(endX) = 10, and *(endY) = 20 
   * 
   * ------------------------------------------------------------------
   * 
   * NOTE: Make sure that you do *not* go outside the image. So, the 
   * minimum value x and y can take is 0, and the maximum values they
   * can take is SIZEX-1 and SIZEY-1. If it tries to go past these, 
   * keep it in the same location.
   * 
   * For example, If the turtle is at (0,0) facing left, and it moves
   * forward for 100 steps, then turns right and moves forward another
   * 100 steps, it's location will not change. (because there are no 
   * pixels to the left or above).
   * 
   * ------------------------------------------------------------------
   *  
   * The drawLine() function in imgUtils.c will draw lines between 2 
   * points you have given it. It is your job to make sure that these 
   * are the correct ones. It's parameters are:
   * 
   *      - im    - An Image struct pointer. Here you should just pass in
   *                the 'im' parameter you got in this function.
   *      - x1,y1 - The (x,y) location of start point of the line
   *      - x2,y2 - The (x,y) location of end point of the line
   *      - col   - The colour to draw the line in [0-255]
   *          
   * Note that this function only draws horizontal and vertical lines,
   * so either the x values or the y values of the start and end point 
   * must be the same. Both these points *must* also be within the
   * image. [ 0 <= x < SIZEX,  0 <= y < SIZEY ]
   */

   if (head==NULL){return;}
   
   CmdNode *p= NULL;
   p=head;
   int colour=0;
   int x = 0; int y = 0;
   int pen_check=1;
   
   int check_up=0;
   int check_down=0;
   int check_right=1;
   int check_left=0;
   int num;
   
   while (p!=NULL)
   {
	   
	   num = p->val;
	   if (strcmp(p->cmd, "penup")==0 && pen_check==1)
	   {
		   pen_check=0;
		   
	   }
	   
	   if (strcmp(p->cmd, "pendown")==0 && pen_check==0)
	   {
		   pen_check=1;
		   // printf(" in pendown (%d,%d)\n",x,y);
	   }
	   
	   if (strcmp(p->cmd, "colour")==0)
	   {
		   if (p->val>=0 && p->val<=255)
		   {
			   colour= p->val;
		   }
	   }
	   
	   if (strcmp(p->cmd, "right")==0)
	   {
		   
		   if (check_right==1)
		   {
			   check_right=0;
			   check_down=1;
			   // printf("pointing down\n");
		   }
		   else if (check_left==1)
		   {
			   check_left=0;
			   check_up=1;
			   // printf("pointing up\n");
		   }
		   else if (check_up==1)
		   {
			   check_up=0;
			   check_right=1;
			   // printf("pointing right\n");
		   }
		   else if(check_down==1)
		   {
			   check_down=0;
			   check_left=1;
			   // printf("pointing left\n");
		   } 
		   else {;}
	   }
	   
	   if (strcmp(p->cmd, "left")==0)
	   {
		   
		   if (check_right==1)
		   {
			   printf("point up\n");
			   check_right=0;
			   check_up=1;
		   }
		   else if (check_left==1)
		   {
			   check_left=0;
			   check_down=1;
			   // printf("pointing down\n");
		   }
		   else if (check_up==1)
		   {
			   check_up=0;
			   check_left=1;
			   // printf("pointing left\n");
		   }
		   else if (check_down==1)
		   {
			   check_down=0;
			   check_right=1;
			   // printf("pointing right\n");
		   }
		   else {;}
		   
	   }
	   
	   
	   if (strcmp(p->cmd, "forward")==0 && pen_check==0)
	   {
		   
		   if (check_right==1 && (x + num) < SIZEX)
		   {
			   x=x+num;
			   
		   }
		   else if (check_right==1 && (x + num) >= SIZEX)
		   {
			   x=SIZEX-1;
			   
		   }
		   else if (check_left==1 && (x-num) >= 0)
		   {
			   x=x-num;
			   
		   }
		   else if (check_left==1 && (x-num) < 0)
		   {
			   x=0;
			   
		   }
		   else if (check_up==1 && (y-num) >=0)
		   {
			   y=y-num;
		   }
		   else if (check_up==1 && (y-num) < 0)
		   {
			   y=0;
		   }
		   else if (check_down==1 && (y+num) < SIZEY)
		   {
			   y=y+num;
		   }
		   else if (check_down==1 && (y+num) >= SIZEY)
		   {
			   y=SIZEY-1;
		   }
		   
		   else
		   {
				;
		   }
		   
		   
	   }
	   
	   if (strcmp(p->cmd, "forward")==0 && pen_check==1)
	   {
		   
		   if (check_right==1 && (x + num) < SIZEX)
		   {
			   drawLine(im, x, y, x+num, y, colour);
			   x=x+num;
			   
		   }
		   else if (check_right==1 && (x + num) >= SIZEX)
		   {
			   drawLine(im, x, y, SIZEX-1, y, colour);
			   x=SIZEX-1;
			   
		   }
		   else if (check_left==1 && (x-num) >= 0)
		   {
			   drawLine(im, x, y, x-num, y, colour);
			   x=x-num;
			   
		   }
		    else if (check_left==1 && (x-num) < 0)
		   {
			   drawLine(im, x, y, 0, y, colour);
			   x=0;
			   
		   }
		   else if (check_up==1 && (y-num) >=0)
		   {
			   drawLine(im, x, y, x, y-num, colour);
			   y=y-num;
		   }
		   else if (check_up==1 && (y-num) < 0)
		   {
			   drawLine(im, x, y, x, 0, colour);
			   y=0;
		   }
		   else if (check_down==1 && (y+num) < SIZEY)
		   {
			   drawLine(im, x, y, x, y+num, colour);
			   y=y+num;
		   }
		   else if (check_down==1 && (y+num) >= SIZEY)
		   {
			   drawLine(im, x, y, x, SIZEY-1, colour);
			   y=SIZEY-1;
		   }
		   else {;}
		   
	   }
	   
	   
	   if (strcmp(p->cmd, "backward")==0 && pen_check==0)
	   {
		   
		   if (check_left==1 && (x + num) < SIZEX)
		   {
			   x=x+num;
			   
		   }
		   else if (check_left==1 && (x + num) >= SIZEX)
		   {
			   x=SIZEX-1;
			   
		   }
		   else if (check_right==1 && (x-num) >= 0)
		   {
			   x=x-num;
			   
		   }
		   else if (check_right==1 && (x-num) < 0)
		   {
			   x=0;
			   
		   }
		   else if (check_down==1 && (y-num) >=0)
		   {
			   y=y-num;
		   }
		   else if (check_down==1 && (y-num) < 0)
		   {
			   y=0;
		   }
		   else if (check_up==1 && (y+num) < SIZEY)
		   {
			   y=y+num;
		   }
		   else if (check_up==1 && (y+num) >= SIZEY)
		   {
			   y=SIZEY-1;
		   }
		   
		   else
		   {
				;
		   }
		   
		   
	   }
	   
	   if (strcmp(p->cmd, "backward")==0 && pen_check==1)
	   {
		   
		   if (check_left==1 && (x + num) < SIZEX)
		   {
			   drawLine(im, x, y, x+num, y, colour);
			   x=x+num;
			   
		   }
		   else if (check_left==1 && (x + num) >= SIZEX)
		   {
			   drawLine(im, x, y, SIZEX-1, y, colour);
			   x=SIZEX-1;
			   
		   }
		   else if (check_right==1 && (x-num) >= 0)
		   {
			   drawLine(im, x, y, x-num, y, colour);
			   x=x-num;
			   
		   }
		   else if (check_right==1 && (x-num) < 0)
		   {
			   drawLine(im, x, y, 0, y, colour);
			   x=0;
			   
		   }
		   else if (check_down==1 && (y-num) >=0)
		   {
			   drawLine(im, x, y, x, y-num, colour);
			   y=y-num;
		   }
		   else if (check_down==1 && (y-num) < 0)
		   {
			   drawLine(im, x, y, x, 0, colour);
			   y=0;
		   }
		   else if (check_up==1 && (y+num) < SIZEY)
		   {
			   drawLine(im, x, y, x, y+num, colour);
			   y=y+num;
		   }
		   else if (check_up==1 && (y+num) >= SIZEY)
		   {
			   drawLine(im, x, y, x, SIZEY-1, colour);
			   y=SIZEY-1;
		   }
		   else {;} 
	   }
	   //******************** LOOP *************************************
	   if (strcmp(p->cmd, "loop")==0)
	   {
		   for (int i=0; i<p->val; i++)
		   {
			   struct cmdnode *p1= NULL;
			   p1=p->loop_head;
			   while (p1!=NULL)
			   {
			   
				   num = p1->val;
				   if (strcmp(p1->cmd, "penup")==0 && pen_check==1)
				   {
					   pen_check=0;
					   
				   }
				   
				   if (strcmp(p1->cmd, "pendown")==0 && pen_check==0)
				   {
					   pen_check=1;
					   // printf(" in pendown (%d,%d)\n",x,y);
				   }
				   
				   if (strcmp(p1->cmd, "colour")==0)
				   {
					   if (p1->val>=0 && p1->val<=255)
					   {
						   colour= p1->val;
					   }
				   }
				   
				   if (strcmp(p1->cmd, "right")==0)
				   {
					   
					   if (check_right==1)
					   {
						   check_right=0;
						   check_down=1;
						   // printf("pointing down\n");
					   }
					   else if (check_left==1)
					   {
						   check_left=0;
						   check_up=1;
						   // printf("pointing up\n");
					   }
					   else if (check_up==1)
					   {
						   check_up=0;
						   check_right=1;
						   // printf("pointing right\n");
					   }
					   else if(check_down==1)
					   {
						   check_down=0;
						   check_left=1;
						   // printf("pointing left\n");
					   } 
					   else {;}
				   }
				   
				   if (strcmp(p1->cmd, "left")==0)
				   {
					   
					   if (check_right==1)
					   {
						   // printf("point up\n");
						   check_right=0;
						   check_up=1;
					   }
					   else if (check_left==1)
					   {
						   check_left=0;
						   check_down=1;
						   // printf("pointing down\n");
					   }
					   else if (check_up==1)
					   {
						   check_up=0;
						   check_left=1;
						   // printf("pointing left\n");
					   }
					   else if (check_down==1)
					   {
						   check_down=0;
						   check_right=1;
						   // printf("pointing right\n");
					   }
					   else {;}
					   
				   }
				   
				   
				   if (strcmp(p1->cmd, "forward")==0 && pen_check==0)
				   {
					   
					   if (check_right==1 && (x + num) < SIZEX)
					   {
						   x=x+num;
						   
					   }
					   else if (check_right==1 && (x + num) >= SIZEX)
					   {
						   x=SIZEX-1;
						   
					   }
					   else if (check_left==1 && (x-num) >= 0)
					   {
						   x=x-num;
						   
					   }
					   else if (check_left==1 && (x-num) < 0)
					   {
						   x=0;
						   
					   }
					   else if (check_up==1 && (y-num) >=0)
					   {
						   y=y-num;
					   }
					   else if (check_up==1 && (y-num) < 0)
					   {
						   y=0;
					   }
					   else if (check_down==1 && (y+num) < SIZEY)
					   {
						   y=y+num;
					   }
					   else if (check_down==1 && (y+num) >= SIZEY)
					   {
						   y=SIZEY-1;
					   }
					   
					   else
					   {
							;
					   }
					   
					   
				   }
				   
				   if (strcmp(p1->cmd, "forward")==0 && pen_check==1)
				   {
					   
					   if (check_right==1 && (x + num) < SIZEX)
					   {
						   drawLine(im, x, y, x+num, y, colour);
						   x=x+num;
						   
					   }
					   else if (check_right==1 && (x + num) >= SIZEX)
					   {
						   drawLine(im, x, y, SIZEX-1, y, colour);
						   x=SIZEX-1;
						   
					   }
					   else if (check_left==1 && (x-num) >= 0)
					   {
						   drawLine(im, x, y, x-num, y, colour);
						   x=x-num;
						   
					   }
						else if (check_left==1 && (x-num) < 0)
					   {
						   drawLine(im, x, y, 0, y, colour);
						   x=0;
						   
					   }
					   else if (check_up==1 && (y-num) >=0)
					   {
						   drawLine(im, x, y, x, y-num, colour);
						   y=y-num;
					   }
					   else if (check_up==1 && (y-num) < 0)
					   {
						   drawLine(im, x, y, x, 0, colour);
						   y=0;
					   }
					   else if (check_down==1 && (y+num) < SIZEY)
					   {
						   drawLine(im, x, y, x, y+num, colour);
						   y=y+num;
					   }
					   else if (check_down==1 && (y+num) >= SIZEY)
					   {
						   drawLine(im, x, y, x, SIZEY-1, colour);
						   y=SIZEY-1;
					   }
					   else {;}
					   
				   }
				   
				   
				   if (strcmp(p1->cmd, "backward")==0 && pen_check==0)
				   {
					   
					   if (check_left==1 && (x + num) < SIZEX)
					   {
						   x=x+num;
						   
					   }
					   else if (check_left==1 && (x + num) >= SIZEX)
					   {
						   x=SIZEX-1;
						   
					   }
					   else if (check_right==1 && (x-num) >= 0)
					   {
						   x=x-num;
						   
					   }
					   else if (check_right==1 && (x-num) < 0)
					   {
						   x=0;
						   
					   }
					   else if (check_down==1 && (y-num) >=0)
					   {
						   y=y-num;
					   }
					   else if (check_down==1 && (y-num) < 0)
					   {
						   y=0;
					   }
					   else if (check_up==1 && (y+num) < SIZEY)
					   {
						   y=y+num;
					   }
					   else if (check_up==1 && (y+num) >= SIZEY)
					   {
						   y=SIZEY-1;
					   }
					   
					   else
					   {
							;
					   }
					   
					   
				   }
				   
				   if (strcmp(p1->cmd, "backward")==0 && pen_check==1)
				   {
					   
					   if (check_left==1 && (x + num) < SIZEX)
					   {
						   drawLine(im, x, y, x+num, y, colour);
						   x=x+num;
						   
					   }
					   else if (check_left==1 && (x + num) >= SIZEX)
					   {
						   drawLine(im, x, y, SIZEX-1, y, colour);
						   x=SIZEX-1;
						   
					   }
					   else if (check_right==1 && (x-num) >= 0)
					   {
						   drawLine(im, x, y, x-num, y, colour);
						   x=x-num;
						   
					   }
					   else if (check_right==1 && (x-num) < 0)
					   {
						   drawLine(im, x, y, 0, y, colour);
						   x=0;
						   
					   }
					   else if (check_down==1 && (y-num) >=0)
					   {
						   drawLine(im, x, y, x, y-num, colour);
						   y=y-num;
					   }
					   else if (check_down==1 && (y-num) < 0)
					   {
						   drawLine(im, x, y, x, 0, colour);
						   y=0;
					   }
					   else if (check_up==1 && (y+num) < SIZEY)
					   {
						   drawLine(im, x, y, x, y+num, colour);
						   y=y+num;
					   }
					   else if (check_up==1 && (y+num) >= SIZEY)
					   {
						   drawLine(im, x, y, x, SIZEY-1, colour);
						   y=SIZEY-1;
					   }
					   else {;} 
				   }
				   p1=p1->next;
				   
				}//while loop end bracket
			   
		   }//for loop end
		   
	   
	   }//if statement end for loop
	   
	   
	   p=p->next;
	   
   }
   
   *(endX) = x;
   *(endY)=y;

  return;
}

////////////////////////////////////////////////////////////////////////////////////
// All done!
