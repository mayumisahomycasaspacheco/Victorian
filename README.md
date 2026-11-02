# Victorian
Victorian is a small shape game with C++ and Windows Forms, with an old treasure map look.

![Victorian](https://cdn.hackclub.com/01a19798-18e0-79f0-8cd7-79bdc97715fa/captura_de_pantalla_2026-11-01_094450.png)

## How to run it
1. Go to the Releases section of this repository.
2. Dowload.exe and play.

## How to play
- Press **Play** to start the free mode.
- Press **T**, **C**, **E**, **D** or **R** to create a triangle, circle, ellipse, square or rectangle.
- Press the **Carrera** button to watch a race between three shapes, and press **Space** to start it.
- Press **ESC** to go back or leave.

## Made with
- C++/CLI and Windows Forms, in visual Studio.
- GDI+ primitives for all the shapes (no images for the figures, everything is draw with code).
- Pixel art map, made in Aseprite.

## Under the hood
It looks simple, but there's a lot going on behind the scenes:

- **10 classes written from scratch:** one per shape (circle, square, rectangle, elipse, triangle) plus a container class for each one that stores up to 100 live objects.

- **Everything moves on its own:** every shape keeps its own position, speed, size and color, and bounces off the walls without ever escaping the window.

- **Colors stored as integers**, picked at random from a custom antique palette (sepia, old gold, copper, bottle green...).

- **Pixel-perfect scaling:** the 256x144 map is stretched to the whole window with nearest-neighbor, so the pixels stay sharp.

Thanks for playing.

*A project made for YSWS Terra by Hack Club*
