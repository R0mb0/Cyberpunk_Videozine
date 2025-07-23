		Documentation for Solar System World



Table of Contents



Section 1 - Getting a black background
Section 2 - General Info about the Solar System World
Section 3 - If you liked this world....
Section 4 - How this world was created (briefly).


--------------------------------------------

Section 1 - Getting a black background



The solar system world looks a lot better with a completely
black background!  I have recently released a version of
demo4.zip that fixes this problem and also allows you to use TWO
gloves at the same time!  This file is DEMO4B.ZIP.  You should
be able to find it at the same place you found this file (or
demo4.zip).  (Footnote:  DEMO4B is not yet available.  It will
be available at the end of April.  Thank you for your patience.)

If you have a compiler, you can recompile devel4.zip in order to
fix the problem.  Do the following to devel4.zip and recompile:

Change line 347 in world.c to read:

			sscanf(buff, "%*s %d", &sky_color);

add the following lines AFTER line 347 of world.c:

		else if (match(buff, "screenclearcolor ")) /* can have
optional r,g,b at end of line */
			sscanf(buff, "%*s %d", &screen_clear_color);

That's it. Black as night.


--------------------------------------------

Section 2 - General Info about the Solar System World


Are the planets scaled correctly?  Yes, in a sense.  It is
important to realize that if the planets were scaled exactly as
in real life, you'd really only be able to see one planet at a
time (in any detail.)  For example, we're on planet Earth right
now, and the other planets appear only as points of light.  Of
course, the sun is fairly big. (See below)  The point is, if the
planets were scaled EXACTLY, you would not be able to see most
of the planets in the same scene.  You would need some kind of a
"warp drive" vehicle to get to the other planets, or something.


So I cheated a little bit.  I got a chart of the distances from
the sun and diameters of the planets.  I decided that if I just
changed the RATIO of "distance miles" to "diameter miles" I
could get something that was based at least partly in fact.
Relative to each other, the distance of the planets to the sun
is correct.  (Example:  The distance from Jupiter to the Sun is
5 times the distance from Earth to the Sun.  This holds true in
my model.)  Relative to each other, the diameter of the planets
is also correct.  (Example:  The diameter of Jupiter is 11 times
the diameter of Earth.  This holds true in my model.)  What is
NOT proportional is the ratio of the distance from the sun to
the diameter of the planet.  (Example: Distance from Earth to
sun is 92,956,000 miles and diameter of Earth is 7,926 miles.
The ratio of distance to diameter is 11,728.  This does not hold
true in my model.)  I should also mention the sun is actually
much bigger (proportionally) than I made it in the model.  It
was just way too big so I shrunk it by a factor of 10 or
something, I don't remember now.  In reality the Sun is way, way
larger than Jupiter.  Such are the sacrifices in low-end VR.


How about the rotational period?  It may not be immediately
apparent, but even the larger planets are traveling around the
Sun (watch them for minute at a close distance).  Again, the
orbits are correct relative to the other planets.  It takes
almost 12 "Earth" years (in "real" reality) for Jupiter to
travel around the Sun.  In this "virtual" reality, Jupiter makes
a complete circle once for every twelve times that the earth
makes a complete circle.  Fortunately, in VR you do not have to
wait 365 days for the Earth to orbit the Sun (as you do in
"real" reality)!


By the way, you have to travel out pretty far in order to get to
Pluto.  You can't even see it unless you go way out to Neptune.
It appears as a small white dot that moves against the
stationary "stars".  If you go toward it, it will eventually
materialize into a "planet."  Cool, huh?


There are a lot of things about the solar system that are
blatantly wrong.  First, there are no moons around any of the
planets, no asteroid belt, no comets, and obviously the colors
are very crude.  Also, the planets are "tilted" slightly in
their orbits (relative to the plane of the Earth) and I didn't
have the time / patience to model this.  Pluto's tilt is in fact
17.2 degrees which would be very noticeable.  The planet's
orbits are elliptical in real reality, and this was not modeled.
 Pluto actually gets closer to the Sun than Neptune during a
large part of its orbit.  I used "average" distance from the
Sun.  Saturn is not the only planet with rings, and in fact
Saturn's rings are a very crude approximation.  You should be
getting the picture by now.  I tried to make the model accurate
enough to hold people's interest for at least a few minutes.  It
might be useful educationally as introduction to the solar
system but this model is by no means definitive.  You win some,
you lose some.



--------------------------------------------

Section 3 - If you liked this world....


Why not hire me to create your own custom world for REND386?
The solar system world took me about four days.  I will
guarantee that I can create ANY world with less than 1000
polygons in five working days or less.  This includes object
rotation as well, within the limits of "demo4.exe."  My rate for
this type of work is $20/hr.  So your company can have its own
custom designed world for $800.  I do not work from blueprints
but rather from a general description of the world.  That is,
you could order something that resembles a roller coaster but
you can't order an accurate model of a B-17 bomber.  Contact


Mark Pflaging, President
Flage Labs
10 Marathon Place
Romney, WV 26757
(304)-822-7617

email: 70233.1552@CompuServe.COM



--------------------------------------------

Section 4 - How this world was created (briefly).


First, I made some general observations about the task I had to
perform.  I realized I was limited to a fixed number of
polygons, somewhere between 500 and 1000.  My first thought was
to divide 750 polygons into 10 spheres (nine planets plus the
sun.)  I knew I'd want a few left over for Saturn's rings.  So
that left 75 polygons per sphere.  I thought, "that's going to
look stupid.  Jupiter, whose diameter is over 10 times that of
Earth's, is going to be made of the same number of polygons?"
(Keep in mind that the surface area of a sphere is proportional
to the SQUARE of the diameter, making Jupiter's surface area 100
times as big as the Earth's.  So I should give the bigger
planets more polygons.  I found a program to generate spheres
(IRIT and IRIT2PLG) but it generated the "football-type" spheres
(as I call them).  They are composed of half-circles rotated
about an axis.  It's an obvious way to do it, but there are
"nipples" at the north and south poles which are kind of
irritating.  In addition, you can only create spheres with a
certain number of polygons (in other words, you can't specify
that you want a sphere made out of 93 polygons.  I wrote a quick
program to generate a "different" kind of sphere, what I call
the "soccer-ball" type.  (Soccer balls have no "nipple", the
polygons are all about the same size and shape.)  This gave me
more choice when determining how many polys were going to be in
each planet.  Listed below are the heavenly bodies, the number
of polygons, and the type of sphere in the final world.


Body		Polys		Type
------		------		------
Sun		96		Soccer
Mercury		32		Football
Venus		54		Soccer
Earth		54		Soccer
Mars		32		Football
Jupiter		96		Soccer
Saturn		96		Soccer
Uranus		72		Football
Neptune		72		Football
Pluto		24		Soccer

I made sure all the various spheres were of a "unit" size, then
I began scaling them according to their relative sizes.  I wrote
a little scaling program to do this.  Then I moved the planets
according to their relative distance to the sun.  I did this by
specifying translation offsets on the appropriate lines in
"solarsys.wld."  (At this point I realized that I would have to
choose a "diameter to distance" ratio as noted in Section 2
above.)  Everything was looking good except the planets were all
red and stationary.

I started experimenting with the "sculspin task" which is not
actually documented in "demo4.zip", but it is pretty easy to
figure out since there are a few examples in "demo4.zip".
Unfortunately the planets were all rotating around their own
axis instead of around the sun!  I realized I would have to
write a "slide" program which offsets the coordinates in the
actual ".plg" files, so I did.  In retrospect it might have been
possible to do this another way...  I also knew that the loading
and saving of objects in "demo4.exe" is a little bit warped, and
that I was better off coloring in the planets before "sliding"
them.

You can color objects using menu commands from within "demo4"
itself.  Hit 'X' for "Invokes Extra Features".  Hit 'C' for
"Choose Color"  Then select a color from the palette with the
mouse.  Hit 'X' again, then hit 'P' for "Paint Polys".  The
scene will freeze.  Move the mouse cursor to point at a polygon,
then hit the left mouse button.  The polygon should change
color.  You can keep painting polys until you hit a keyboard
key.  You can hold down the left mouse button to paint a larger
area.  I like this feature, it's really neat.

I colored the planets, added rings to Saturn with another
"quickie" program I wrote, and "slid" them over.  Finally, the
rotated around the sun, and the colors looked all right.  I'm
sure if you were doing it, you'd have used different colors, but
that's what makes the (real) world great, right? Everyone's
different.  The stars have an interesting little story behind
them.  Bernie Roehl had posted a 30 line program to generate a
random "starfield".  Unfortunately, if there were any other
objects in the world along with the starfield, the colors of
those objects were essentially random.  So I let it go for a few
months thinking, "someone will figure out how to fix this."
Finally I heard that Todd Porter had fixed it, but I couldn't
find the code on the Internet.  So I took a hard look at the
generated "stars.plg" and noticed that the "polygons" were
actually made up of just one vertex each!  ("Unigons" if you
will.)  I had been talking with Bernie and Joe Gradecki at the
VR Systems conference and I remembered Joe telling me that
"bigons" (polygons with just two vertices) worked (that's how
Joe did the racket in his virtual racquetball game).  So I made
the "unigons" into "bigons".  Each of the "bigons" has the same
beginning and ending vertex.  Viola!  It worked.



And on the sixth day I rested.......



