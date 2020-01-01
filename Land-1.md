# Land-1
PPC, 278 Points

Author: lys0829

Writeup By: **mayawan**

## Description
You can ask 128 times. Can you solve this problem?

http://34.82.101.212:10005/tasks/Level1/submissions Please use your username and password on ctfd to login the Judge Server.

Remote Server: Ubuntu 18.04

This is a programming contest problem. And the problem type is Special Judge.
Please read the statement.pdf for problem detail.
The release.zip is some code for you to let you can test on your own computer.
The grader.c in release.zip is different from the judge server's grader.c,
but all the global variable in grader.c is still in the judge server's grader.c.
Your goal is to write a C code and submit it to the system to get Accepted.
If you get Accepted, then you can get the Flag. Please don't attack the Judge System.
But you can attack the problem by your C code.
You must wait for 2 minute between every submission.

[statement.pdf](https://drive.google.com/open?id=19r1T1aeWgGj_zkFlrzUd9Zk1fTMc4rf1)

[release.zip](https://drive.google.com/open?id=1PcajpFG1y7E_Nm4fVqPwPHccsSllgdGt)

## Challenge
There is square Cartesian coordinate plane bound between 0 to 10<sup>9</sup>.
Inside of the plane is a rectangle that is bound between `x1`, `x2`, `y1`, `y2` ( 0 <= x1 < x2 <= 10<sup>9</sup>, 0 <= y1 < y2 <= 10<sup>9</sup>).

Using the `area(int x1, int y1, int x2, int y2)` function, you can find the intersecting area of the rectangle and the rectangle created by the parameters. 
You can call this function at most 128 times.

Find the values of `x1`, `x2`, `y1`, `y2` of the rectangle
and store them in the `rectangle` class in `a`, `b`, `c`, `d` respectively while calling the area function at most 128 times.

## Solution
Begin by finding the total area of the rectangle by calling `area(0,0, 1000000000, 1000000000)`.

If `total` is 10<sup>18</sup>, then the rectangle must be `0, 0, 1000000000, 1000000000`

Then do two binary searches to find the lower bounds (`x1` and `y1`) of the rectangle.
***
Initial Condition: `lb = 1, rb = 99999999`

Termination: `lb > rb`

Searching left: `rb = mid - 1`

Searching right: `lb = mid + 1`
***
With each iteration of the binary searches,
you check `area(mid, 0, 1000000000, 1000000000) < total` for searching `x1`
and `area(0, mid, 1000000000, 1000000000) < total` for searching `y1`.
If true, search the left half.
If false, search the right half.
`x1` and `y1` will be the the highest value of mid that results in a false.

The reason why the bounds are `1` and `99999999` is because the judge checks the parameters of the `area` function.
If `x1 >= x2 || y1 >= y2`, it is an invalid query and results in a wrong answer.

Once the lower bounds have been found, then find the change of area between `total` and `x1 + 1`.
This value (size_y) will be the size of the rectangle in the y direction.
Dividing `total` by `size_y` will get you the size of the rectangle in the x direction.
`x1 + size_x` will result in `x2` and `y1 + size_y` will result in `y2`.

Now you have all the values and they must be stored into `rectangle`.

Worst case scenario is 62 calls.

You can find my solution [here](https://github.com/cnbtwriteups/BambooFoxCTF/blob/master/Land.c)
