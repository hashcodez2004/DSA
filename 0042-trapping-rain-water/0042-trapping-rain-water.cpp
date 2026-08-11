class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;

        while (l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if (lmax < rmax) {
                ans += lmax - height[l];
                l++;
            } else {
                ans += rmax - height[r];
                r--;
            }
        }

        return ans;
    }
};


/*
===============================================================================
TRAPPING RAIN WATER - INTUITION AND DETAILED EXPLANATION
===============================================================================

PROBLEM IDEA
------------
For every position i, the amount of water that can stay above that position is:

    water[i] = min(leftMax[i], rightMax[i]) - height[i]

where:

    leftMax[i]  = maximum height on the left side including i
    rightMax[i] = maximum height on the right side including i

The main challenge is calculating these maximum values efficiently.


===============================================================================
1. DIFFERENT APPROACHES
===============================================================================

APPROACH 1: BRUTE FORCE
-----------------------
For every index, we can separately find:

    maximum height on its left
    maximum height on its right

Then:

    water = min(leftMax, rightMax) - height[i]

If we scan the left and right side for every index, each index can take O(n)
work.

Therefore:

    Time  = O(n^2)
    Space = O(1)

This works, but it is too slow for large inputs.


APPROACH 2: TWO ARRAYS (LEFT MAX + RIGHT MAX)
----------------------------------------------
We can precompute:

    leftMax[i]  = maximum height from 0 to i
    rightMax[i] = maximum height from i to n-1

Then each index can be solved in O(1).

For example:

    height = [4, 2, 0, 3, 2, 5]

leftMax:

    [4, 4, 4, 4, 4, 5]

rightMax:

    [5, 5, 5, 5, 5, 5]

Then for every index:

    water[i] = min(leftMax[i], rightMax[i]) - height[i]

Time:

    O(n)

Space:

    O(n) for two arrays
    (technically O(2n), which is still O(n))


APPROACH 3: REDUCE THE EXTRA SPACE
----------------------------------
We can use one array for one side and keep the other maximum in a variable.

This reduces the practical extra space from two arrays to one array.

Time:

    O(n)

Space:

    O(n)


APPROACH 4: OPTIMAL TWO POINTER APPROACH
----------------------------------------
This is the approach used in the code above.

Time:

    O(n)

Extra Space:

    O(1)

This is the optimal approach because we process every position only once and
use only a few variables.


===============================================================================
2. THE KEY IDEA OF THE TWO POINTER APPROACH
===============================================================================

We keep two pointers:

    l = left side
    r = right side

And two values:

    lmax = maximum height encountered so far from the left
    rmax = maximum height encountered so far from the right

Initially:

    lmax = 0
    rmax = 0


The important decision is:

    if (lmax < rmax)

        process the LEFT side

    else

        process the RIGHT side


This may look strange at first.

The obvious formula for a position is:

    min(leftMax, rightMax) - height[i]

So why don't we explicitly calculate min(lmax, rmax) every time?

Because once we know which maximum is smaller, we already know which side is
the limiting boundary.


===============================================================================
3. WHY CAN WE PROCESS THE LEFT SIDE WHEN lmax < rmax?
===============================================================================

Suppose:

    lmax = 4
    rmax = 7

Then:

    lmax < rmax

The left boundary is only 4, while the right boundary is at least 7.

Therefore, the maximum water level possible at the current left position is
definitely limited by 4.

Why?

Because the right side already has a boundary of height 7.

So even if there are many different heights somewhere between l and r, they
cannot make the water level at the current left position less than 4.

We already have:

    left boundary = 4
    right boundary >= 7

Therefore:

    min(4, 7) = 4

So the amount of water at the current left position is guaranteed to be:

    lmax - height[l]


This is exactly why the code can safely do:

    ans += lmax - height[l];
    l++;


===============================================================================
4. THE IMPORTANT QUESTION:
   "WHAT IF A TALLER BUILDING LIKE 10 EXISTS SOMEWHERE IN BETWEEN?"
===============================================================================

This is a very common doubt.

Consider:

                    10
                    |
        4           |           5
        |           |           |
        |     1     |           |
--------|-----|-----|-----------|----
              l                 r

Suppose:

    height[l] = 1
    lmax = 4
    rmax = 5

There is a building of height 10 somewhere between them.

Now:

    lmax < rmax

because:

    4 < 5

So we process the left side:

    water = lmax - height[l]
          = 4 - 1
          = 3


At first this may seem wrong:

"How can we decide the water is 3 when there is a 10 in between?"

The answer is that the 10 does not reduce the water.

We already know there is a left boundary of height 4.

We also already know there is a right boundary of height 5.

Therefore the water level at the current position is guaranteed to be:

    min(4, 5) = 4

The 10 in between is irrelevant to this particular position.

In fact, the 10 only makes the situation safer.

After processing the current left position, the left pointer moves toward the
10.

When we reach the 10:

    lmax = max(lmax, 10)

so:

    lmax = 10

Now suppose:

    rmax = 5

Then:

    lmax < rmax

becomes:

    10 < 5

which is false.

Therefore the algorithm switches to processing the RIGHT side.

So the taller building is not ignored. It is discovered when the pointer
reaches it, and lmax is updated accordingly.


===============================================================================
5. ANOTHER IMPORTANT CASE
===============================================================================

Suppose:

    lmax = 4
    rmax = 3

and:

    height[l] = 1


Here:

    lmax < rmax

is false because:

    4 < 3  -> false

So we DO NOT process the left side.

Instead, we process the right side:

    water at right = rmax - height[r]

Why?

Because now the right side is the smaller boundary.

The current right position is guaranteed to have a left boundary of at least 4,
but the known right boundary is only 3.

Therefore:

    min(4, 3) = 3

So the right side is the bottleneck.


===============================================================================
6. WHY THE SMALLER MAXIMUM IS THE SAFE SIDE TO PROCESS
===============================================================================

This is the heart of the entire algorithm.

CASE 1:

    lmax < rmax

Then:

    min(lmax, rmax) = lmax

So the left side is completely determined by lmax.

We can safely calculate:

    water[l] = lmax - height[l]

and move:

    l++


CASE 2:

    rmax <= lmax

Then:

    min(lmax, rmax) = rmax

So the right side is completely determined by rmax.

We can safely calculate:

    water[r] = rmax - height[r]

and move:

    r--


We do NOT need to know the exact maximum on the opposite side.

We only need to know that the opposite side is at least as tall as the
smaller boundary we are using.


===============================================================================
7. WHY A FUTURE ELEMENT CANNOT BREAK OUR DECISION
===============================================================================

This is another important part of understanding the algorithm.

Suppose:

    lmax = 4
    rmax = 8

We decide to process the left side.

Now imagine that there is a future element somewhere on the right with height:

    2

Could that destroy our calculation?

No.

Because rmax is the maximum height we have already seen from the right.

If rmax = 8, then there is already a height-8 boundary on the right side.

A future element of height 2 does not remove that boundary.

The maximum can only stay the same or increase.

Therefore:

    rmax can never decrease
    lmax can never decrease

This is why once one side's maximum is smaller, that side can be safely
processed.


===============================================================================
8. WHAT DOES "LEFT BOUNDARY IS FIXED" REALLY MEAN?
===============================================================================

Suppose:

    lmax = 4
    rmax = 6

We say the left boundary is effectively fixed for the current left position.

This does NOT mean that lmax will always remain 4.

Later, we might encounter a height of 10 and then:

    lmax = 10

What it means is:

For the CURRENT left position, we already know that the right side has a
boundary of at least 6, which is taller than the current left maximum of 4.

Therefore the current position's water level is guaranteed to be limited by 4.

Future taller buildings cannot make the water level at this already-processed
position smaller.

That is why we can permanently calculate its contribution and move on.


===============================================================================
9. WALKING THROUGH THE CODE
===============================================================================

We start with:

    int l = 0, r = n - 1;
    int lmax = 0, rmax = 0;

The pointers represent the two ends of the unprocessed portion.

Then:

    while (l < r)

we update the maximums:

    lmax = max(lmax, height[l]);
    rmax = max(rmax, height[r]);

Now we decide which side to process.

If:

    lmax < rmax

then:

    ans += lmax - height[l];
    l++;

Otherwise:

    ans += rmax - height[r];
    r--;


The important point is that we are NOT blindly calculating:

    min(lmax, rmax) - height[l]

or:

    min(lmax, rmax) - height[r]

Instead, we use the comparison to prove which side is the bottleneck.


===============================================================================
10. WHY DO WE UPDATE lmax/rmax BEFORE CALCULATING WATER?
===============================================================================

Consider:

    height[l] = 4
    lmax = 2

The actual maximum on the left including the current position is now 4.

So we first do:

    lmax = max(lmax, height[l]);

which gives:

    lmax = 4

Then we calculate:

    lmax - height[l]
    = 4 - 4
    = 0

This is correct because a building cannot hold water above itself.

The same logic applies to rmax.


===============================================================================
11. WHY DO WE CHECK ans.size() IN SOME TOPOLOGICAL SORT PROBLEMS?
===============================================================================

Not relevant to this problem.

For Trapping Rain Water, we simply accumulate the amount of water and return
ans.

There is no cycle detection or graph involved here.


===============================================================================
12. COMPLEXITY
===============================================================================

BRUTE FORCE:

    Time  = O(n^2)
    Space = O(1)


TWO ARRAYS:

    Time  = O(n)
    Space = O(2n) = O(n)


ONE ARRAY + VARIABLES:

    Time  = O(n)
    Space = O(n)


TWO POINTERS (CURRENT CODE):

    Time  = O(n)
    Space = O(1)


The two-pointer approach is therefore optimal in both time and extra space.

Every index is processed at most once by one of the two pointers.


===============================================================================
13. THE ONE-LINE INTUITION TO REMEMBER
===============================================================================

If:

    lmax < rmax

then the LEFT side is the bottleneck, because the right side is already tall
enough to support water up to lmax.

So process left.

If:

    rmax <= lmax

then the RIGHT side is the bottleneck, because the left side is already tall
enough to support water up to rmax.

So process right.


In short:

    SMALLER MAXIMUM = SIDE WE CAN SAFELY PROCESS


That is the key idea behind the O(1) space two-pointer solution.


===============================================================================
14. FINAL MENTAL MODEL
===============================================================================

Think of lmax and rmax as two walls.

If the left wall is shorter:

            left wall             right wall
                4                     7
                |                     |
                |       water         |
                |~~~~~~~~~~~~~~~~~~~~~|
                |                     |

the water level near the left side can safely be decided using height 4,
because the right wall is already taller.

If the right wall is shorter:

            left wall             right wall
                7                     4
                |                     |
                |       water         |
                |~~~~~~~~~~~~~~~~~~~~~|
                |                     |

the water level near the right side can safely be decided using height 4.

We keep moving inward, always processing the side whose known maximum is
smaller.

That is how we avoid storing leftMax[] and rightMax[] arrays while still
getting the correct answer in O(n) time and O(1) extra space.
===============================================================================
*/
