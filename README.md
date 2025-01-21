# 42-Cursus-Rank02-push_swap
Push_swap for 100% as of November 2024. Might add checker later.

Uses turk algorithm which does sorting when pushing from a to b, keeping in mind which end of b to push to, to minimize rb\rrb operations, and then pushes everything back to a. 

100 numbers would give you 630-640 operations (always under 700, 5\5); 500 numbers will on average give 5300-5400 but approximately 1\6 of the time exceed 5500 since number of operations is not directly proportionate like in radix, but depends on how initially spread out the numbers are. Since there is no moulinette, only humans, if you can explain this - should also be ok for 5\5.
