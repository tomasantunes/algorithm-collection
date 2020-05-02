# inspired by code from http://csharphelper.com/blog/2015/10/draw-a-triangular-grid-in-c/

from PIL import Image, ImageDraw
import math

w = 800
h = 800

im = Image.new('RGB', (w, h), (255, 255, 255)) 
draw = ImageDraw.Draw(im) 

triangleHeight = 50

def paint():
	drawTriangularGrid(0, w, 0, h, triangleHeight)

def drawTriangularGrid(xmin, xmax, ymin, ymax, height):
	width = triangleWidth(height)
	row = 0

	for y in xrange(0, int(ymax + width / 2), height):
		x = 0
		if (row % 2 == 0): 
			x = width / 2

		points = [
			(x, y),
			(x + width / 2, y + height),
			(x - width / 2, y + height)
		]

		while (x <= xmax):
			draw.polygon(points, fill=(255,255,255), outline=(0,0,0))
			points[0] = (points[0][0] + width, points[0][1])
			points[1] = (points[1][0] + width, points[1][1])
			points[2] = (points[2][0] + width, points[2][1])
			x += width
		
		row += 1

def triangleWidth(height):
	return (2 * height / math.sqrt(3))

def pointToTriangle(x, y, height, row, col):
	width = triangleWidth(height)
	row = int(y / height)
	col = int(x / width)

	dy = (row + 1) * height - y
	dx = x - col * width
	if (row % 2 == 1):
		dy = height - dy
	if (dy > 1):
		if (dx < width / 2):
			# Left half of triangle.
			ratio = dx / dy;
			if (ratio < 1 / math.sqrt(3)):
				col -= 0.5
		else:
			# Right half of triangle.
			ratio = (width - dx) / dy
			if (ratio < 1 / math.sqrt(3)):
				col += 0.5

def triangleToPoints(height, row, col):
	width = triangleWidth(height)
	y = row * height
	x = (col + 0.5) * width

	# See if this triangle should be drawn
	# right-side up or upside down.
	whole_col = (math.abs(col - int(col)) < 0.1);
	rightside_up = 0
	if (int(row) % 2 == 0):
		# Even row.
		rightside_up = whole_col
	else:
		# Odd row.
		rightside_up = not whole_col

	# Draw the triangle.
	if (rightside_up):
		return [
			(x, y),
			(x + width / 2, y + height),
			(x - width / 2, y + height)
		]
	else:
		return [
			(x, y + height),
			(x + width / 2, y),
			(x - width / 2, y)
		]

paint()

im.show()
