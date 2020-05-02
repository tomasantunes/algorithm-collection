import random
#======================
# parametres
#======================
size_x=15
size_y=15
size_z=15

rand_num=27
#======================
# fin des parametres
#======================

maze=[]

true=1
false=0

possible=0

for n1 in range(size_x):
    maze.append([])
    for n2 in range(size_y):
        maze[n1].append([]) # 0 = way 1 = wall
        for n3 in range(size_z):
            maze[n1][n2].append(0) # 0 = way 1 = wall
   
list_ = []

for n1 in range (size_x * size_y*size_z):
     list_.append([])
     for n2 in range(3):
       list_[n1].append(0)

list_size = -1

def add_list(px, py, pz):
  global list_size, list_, maze, possible
  list_size = list_size+1; print list_size
  list_[list_size][0]=px
  list_[list_size][1]=py
  list_[list_size][2]=pz
  
  maze[px][py][pz] = 0; # 0 = way        
  possible = true

def remove_list(num):
  global list_,list_size  
  a = num
  while (a < list_size):
    list_[a][0]=list_[a + 1][0]
    list_[a][1]=list_[a + 1][1]  
    list_[a][2]=list_[a + 1][2]  
    a = a + 1
  list_size=list_size - 1

pz = 0
while (pz < size_z):
    py = 0
    while (py < size_y):
      px = 0
      while (px < size_x):
        maze[px][py][pz] = 1; # 1 = wall
        px = px + 1
      py = py + 1
    #print maze[px-1]
    pz = pz + 1
pz=0
# Rounding macro
def round(num):
    return int(num + 0.5)

# Adds the start point in the middle of the maze array.
add_list(round(size_x / 2),round(size_y / 2),round(size_z / 2))
random.seed(rand_num)

dir_matrix=[]

# UP
dir_matrix.append( [ [0,-1,0],
                     [-1,-1,0],
                     [-1,-2,0],
                     [0,-2,0],
                     [1,-2,0],
                     [1,-1,0],
                     [0,-1,1],
                     [-1,-1,1],
                     [-1,-2,1],
                     [0,-2,1],
                     [1,-2,1],
                     [1,-1,1],
                     [0,-1,-1],
                     [-1,-1,-1],
                     [-1,-2,-1],
                     [0,-2,-1],
                     [1,-2,-1],
                     [1,-1,-1]]
                     )
          

#RIGHT
dir_matrix.append([[1,0,0],
                     [1,-1,0],
                     [2,-1,0],
                     [2,0,0],
                     [2,1,0],
                     [1,1,0],
                     
                     [1,0,1],
                     [1,-1,1],
                     [2,-1,1],
                     [2,0,1],
                     [2,1,1],
                     [1,1,1],
                     
                     [1,0,-1],
                     [1,-1,-1],
                     [2,-1,-1],
                     [2,0,-1],
                     [2,1,-1],
                     [1,1,-1]]
                   
                     )
          

#DOWN
dir_matrix.append([
                     [0,1,0],
                     [1,1,0],
                     [1,2,0],
                     [0,2,0],
                     [-1,2,0],
                     [-1,1,0],
                     
                     [0,1,1],
                     [1,1,1],
                     [1,2,1],
                     [0,2,1],
                     [-1,2,1],
                     [-1,1,1],
        
                     [0,1,-1],
                     [1,1,-1],
                     [1,2,-1],
                     [0,2,-1],
                     [-1,2,-1],
                     [-1,1,-1]
                         ]
                     
                     )
          

#LEFT
dir_matrix.append([
                     [-1,0,0],
                     [-1,1,0],
                     [-2,1,0],
                     [-2,0,0],
                     [-2,-1,0],
                     [-1,-1,0],

                     [-1,0,1],
                     [-1,1,1],
                     [-2,1,1],
                     [-2,0,1],
                     [-2,-1,1],
                     [-1,-1,1],


                     [-1,0,-1],
                     [-1,1,-1],
                     [-2,1,-1],
                     [-2,0,-1],
                     [-2,-1,-1],
                     [-1,-1,-1]])                     
                 


#CEIL
dir_matrix.append([
                     [-1,-1,1],
                     [-1,0,1],
                     [-1,1,1],
                     [0,-1,1],
                     [0,0,1],
                     [0,1,1],
                     [1,-1,1],
                     [1,0,1],
                     [1,1,1],
                     
                     [-1,-1,2],
                     [-1,0,2],
                     [-1,1,2],
                     [0,-1,2],
                     [0,0,2],
                     [0,1,2],
                     [1,-1,2],
                     [1,0,2],
                     [1,1,2]])
                   
                     
#FLOOR
dir_matrix.append([
                     [-1,-1,-1],
                     [-1,0,-1],
                     [-1,1,-1],
                     [0,-1,-1],
                     [0,0,-1],
                     [0,1,-1],
                     [1,-1,-1],
                     [1,0,-1],
                     [1,1,-1],
                     
                     [-1,-1,-2],
                     [-1,0,-2],
                     [-1,1,-2],
                     [0,-1,-2],
                     [0,0,-2],
                     [0,1,-2],
                     [1,-1,-2],
                     [1,0,-2],
                     [1,1,-2]])

  
def test_dir(px,py,pz,direction,maze):
    dm=dir_matrix
    if  maze[px+dm[direction][0][0]][py+dm[direction][0][1]][pz+dm[direction][0][2]] and\
        maze[px+dm[direction][1][0]][py+dm[direction][1][1]][pz+dm[direction][1][2]] and\
        maze[px+dm[direction][2][0]][py+dm[direction][2][1]][pz+dm[direction][2][2]] and\
        maze[px+dm[direction][3][0]][py+dm[direction][3][1]][pz+dm[direction][3][2]] and\
        maze[px+dm[direction][4][0]][py+dm[direction][4][1]][pz+dm[direction][4][2]] and\
        maze[px+dm[direction][5][0]][py+dm[direction][5][1]][pz+dm[direction][5][2]] and\
        maze[px+dm[direction][6][0]][py+dm[direction][6][1]][pz+dm[direction][6][2]] and\
        maze[px+dm[direction][7][0]][py+dm[direction][7][1]][pz+dm[direction][7][2]] and\
        maze[px+dm[direction][8][0]][py+dm[direction][8][1]][pz+dm[direction][8][2]] and\
        maze[px+dm[direction][9][0]][py+dm[direction][9][1]][pz+dm[direction][9][2]] and\
        maze[px+dm[direction][10][0]][py+dm[direction][10][1]][pz+dm[direction][10][2]] and\
        maze[px+dm[direction][11][0]][py+dm[direction][11][1]][pz+dm[direction][11][2]] and\
        maze[px+dm[direction][12][0]][py+dm[direction][12][1]][pz+dm[direction][12][2]] and\
        maze[px+dm[direction][13][0]][py+dm[direction][13][1]][pz+dm[direction][13][2]] and\
        maze[px+dm[direction][14][0]][py+dm[direction][14][1]][pz+dm[direction][14][2]] and\
        maze[px+dm[direction][15][0]][py+dm[direction][15][1]][pz+dm[direction][15][2]] and\
        maze[px+dm[direction][16][0]][py+dm[direction][16][1]][pz+dm[direction][16][2]] and\
        maze[px+dm[direction][17][0]][py+dm[direction][17][1]][pz+dm[direction][17][2]] and\
        maze[px+dm[direction][7][0]][py+dm[direction][7][1]][pz+dm[direction][7][2]] and\
        maze[px+dm[direction][8][0]][py+dm[direction][8][1]][pz+dm[direction][8][2]] and\
        maze[px+dm[direction][9][0]][py+dm[direction][9][1]][pz+dm[direction][9][2]] and\
        maze[px+dm[direction][10][0]][py+dm[direction][10][1]][pz+dm[direction][10][2]]:        
        return 1
    else:
        return 0
    

"""
Main loop
"""

direction_=round (random.random() * 3);
tries=0

while (list_size > -1):
    
  """
   We choose either the last coordinate or sometimes at random (should
   be a good way to get a maze with a long solution).
  """

  if (random.random() > 0.75):
    choose = round(random.random()*list_size)
  else:
    choose = list_size

  # We choose a direction (0..3)
  direction_ = round(random.random() * 5)
  
  px = list_[choose][0]  
  py = list_[choose][1]
  pz = list_[choose][2]
  
  possible = false  
  tries = 0
                                                                                                                                                                                                             
  while ((possible==false) and (tries < 6)):
    if direction_==0:    #case (0) // up
        if  (py > 1) and ((pz>1) and (pz<size_z-2)):  
          if test_dir(px,py,pz,direction_,maze):       
            add_list(px,py - 1,pz)
  
    elif direction_==1:  #case (1) // right
        if  (px < (size_x - 2)) and ((pz>1) and (pz<size_z-2)):
          if test_dir(px,py,pz,direction_,maze):       
            add_list(px + 1, py,pz)

    elif direction_==2:  #case (2) // down
        if  (py < (size_y - 2)) and ((pz>1) and (pz<size_z-2)):
          if test_dir(px,py,pz,direction_,maze):       
            add_list(px, py + 1,pz)

    elif direction_==3:  #case (3) // left
        if  (px > 1) and ((pz>1) and (pz<size_z-2)):
          if test_dir(px,py,pz,direction_,maze):       
            add_list(px - 1, py,pz)

    elif direction_==4:  #case (4) // ceil
        if  (px > 1) and (py>1) and (py < (size_y - 1)) and (px < (size_x - 1)) and (pz<size_z-2):
          if test_dir(px,py,pz,direction_,maze):       
            add_list(px, py,pz + 1)

    elif direction_==5:  #case (4) // ceil
        if  (px > 1) and (py>1) and (py < (size_y - 1)) and (px < (size_x - 1)) and (pz>1):
          if test_dir(px,py,pz,direction_,maze):       
            add_list(px, py,pz - 1)
                   
    
    tries = tries + 1;
    direction_ = direction_ + 1;
    if direction_ > 5:
        direction_ = 0
        
  if  possible==false:
      remove_list(choose)

pz=0

a = b = 0
ex=0

while a<size_y:
	a+=1
	while b <size_z:
		b+=1	
		print maze[1][a][b],' ',
		if maze[1][a][b]==0:
			ex=1
			break
	if ex==1:
		break	
	b=0
	
print "\n",a, b		
maze[0][a][b] = 0

a = size_z-1
b = size_y-1

while a > 0:
	a-=1
	while b > 0 :
		b-=1	
		if maze[size_x-2][b][a]==0:
			ex=1
			break
	if ex==1:
		break	
	b=0
	
print "\n",a, b		
maze[size_x-1][b][a]=0