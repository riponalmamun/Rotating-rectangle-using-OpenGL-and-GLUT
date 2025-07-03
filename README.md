# Rotating-rectangle-using-OpenGL-and-GLUT


This code creates a rotating rectangle using OpenGL and GLUT.

Display Function: Clears the screen and draws a blue rectangle at the center, which rotates around the Z-axis.

Rotation Logic: The rectangle's rotation is controlled by the angle variable, which is updated every frame in the update() function.

Animation: The update() function modifies the angle by a small amount each time (based on the speed), and calls glutPostRedisplay() to redraw the rectangle, creating continuous rotation.

OpenGL Setup: The init() function initializes OpenGL settings, including the window size, background color, and 2D orthographic projection.

When run, this code displays a rotating rectangle in a window.
