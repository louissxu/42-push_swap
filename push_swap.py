from collections import deque
import sys
import math

def is_sorted(left, right):
    if right:
        return False
    if len(l) <= 1:
      return True
    cur = left[0] - 1
    for val in left:
        if cur >= val:
            return False
        cur = val
    return True


def pb(left, right, moves):
    tmp = left.popleft()
    right.appendleft(tmp)
    moves.append("pb")


def ra(left, right, moves):
    tmp = left.popleft()
    left.append(tmp)
    moves.append("ra")

def rra(left, right, moves):
  tmp = left.pop()
  left.appendleft(tmp)
  moves.append("rra")

def pa(left, right, moves):
    tmp = right.popleft()
    left.appendleft(tmp)
    moves.append("pa")

def rb(left, right, moves):
  tmp = right.popleft()
  right.append(tmp)
  moves.append("rb")

def rrb(left, right, moves):
  tmp = right.pop()
  right.appendleft(tmp)
  moves.append("rrb")

def sa(left, right, moves):
  if len(left) <= 1:
    pass
  else:
    tmp = left.popleft()
    left.appendleft(tmp)
    moves.append("sa")

def sort_3_elements(l, r):
  # Does the mathematical optimal sort of 3 elements
  if len(l) != 3:
    raise ValueError
  new_stack = [None] * 3
  sorted_stack = sorted(l)
  lut = {}
  for i, val in enumerate(sorted_stack):
    lut[val] = i
  for i in range(len(new_stack)):
    new_stack[i] = lut[l[i]]
  solutions_a = {
    (0, 1, 2): [],
    (1, 0, 2): ["sa"],
    (2, 1, 0): ["sa", "rra"],
    (2, 0, 1): ["ra"],
    (0, 2, 1): ["sa", "ra"],
    (1, 2, 0): ["rra"],
  }
  m = []
  m.extend(solutions_a[tuple(new_stack)])
  return m

def sort_2_elements_descending(l, r, moves, stack):
  # Sorts 2 elements descending (high to low)
  if len(stack) != 2:
    raise ValueError
  new_stack = [None] * 2
  sorted_stack = sorted(stack)
  lut = {}
  for i, val in enumerate(sorted_stack):
    lut[val] = i
  for i in range(len(new_stack)):
    new_stack[i] = lut[stack[i]]
  solutions_a = {
    (1, 0): [],
    (0, 1): ["sa"],
  }
  solutions_b = {
    (1, 0): [],
    (0, 1): ["sb"],
  }
  if stack == l:
    moves.extend(solutions_a[tuple(new_stack)])
  if stack == r:
    moves.extend(solutions_b[tuple(new_stack)])

def push_forward_val(l, r, moves, val):
  distance = find_distance_from(l, val)
  while distance > 0:
    ra(l, r, moves)
    distance -= 1
  while distance < 0:
    rra(l, r, moves)
    distance += 1
  pb(l, r, moves)

def sort_4_elements(l, r):
  m = []
  push_forward_val(l, r, m, 0)
  sort_3_elements(l, r, m, l)
  pa(l, r, m)
  return m

def sort_5_elements(l, r):
  # pick across the highest two values
  # sort left
  # sort right
  # push back
  m = []
  push_forward_val(l, r, m, 0)
  push_forward_val(l, r, m, 1)
  m.extend(sort_3_elements(l, r))
  pa(l, r, m)
  pa(l, r, m)
  return m

def radix_sort(l, r):
  # Basic radix sort
  radix = 0
  m = []
  while is_sorted(l, r) == False:
    for i in range(len(l)):
        if l[0] // (2**radix) % 2 == 0:
            pb(l, r, m)
        else:
            ra(l, r, m)
    for i in range(len(r)):
        pa(l, r, m)
    radix += 1
  return m


def double_radix_sort(l, r):
  # Fiddling with the radix sort
  radix = 0
  m = []
  max_radix = (math.log2(len(l)) + 1) // 1
  while radix < max_radix:
    # while any(map(lambda x: x // (2 ** radix) %2 == 0, l)):
    for i in range(len(l)):
        if l[0] // (2**radix) % 2 == 0:
            pb(l, r, m)
        else:
            ra(l, r, m)

    radix += 1
    if radix < max_radix:
      r_1 = len(r)
      for i in range(len(l)):
        if l[0] // (2**radix) % 2 == 0:
          pb(l, r, m)
        else:
          ra(l, r, m)
      for i in range(len(r) - r_1):
        rb(l, r, m)
      for i in range(r_1):
        if r[0] // (2**radix) % 2 != 0:
          pa(l, r, m)
        else:
          rb(l, r, m)
    for i in range(len(r)):
        pa(l, r, m)
    radix += 1
  return m

def split_into_buckets(l, r, num_groups):
  # Splits left to right side in buckets. Splits it into blocks descending
  # Does so on single pass

  num_elements = len(l)
  group_size = num_elements / num_groups

  moves = []
  lower_bound = 0
  upper_bound = lower_bound + group_size
  while l:
    for _ in range(len(l)):
      if lower_bound <= l[0] < upper_bound:
        pb(l, r, moves)
      else:
        ra(l, r, moves)
    lower_bound = upper_bound
    upper_bound = lower_bound + group_size
  return moves

def split_into_buckets_double(l, r, num_groups):
  # Splits left side to right side separated into buckets. Splits it into blocks descending
  # Splits off pairs of groups at a time and expands out
  # For odd number of groups does middle pairs, expands out, and does the highest group last

  num_elements = len(l)
  group_size = num_elements / num_groups

  moves = []

  # - high_high
  # - high_low
  # ...
  # - low_high
  # - low_low
  low_high = num_groups // 2 * group_size
  high_low = low_high
  low_low = low_high - group_size
  high_high = high_low + group_size

  while l:
    # print(f"brackets: {low_low}, {low_high}, {high_low}, {high_high}")
    for _ in range(len(l)):
      if high_low <= l[0] < high_high:
        pb(l, r, moves)
      elif low_low <= l[0] < low_high:
        pb(l, r, moves)
        rb(l, r, moves)
      else:
        ra(l, r, moves)
    low_high = low_low
    low_low -= group_size
    high_low = high_high
    high_high += group_size
      
  return moves

def split_into_buckets_double_2(l, r, num_groups):
  # Same as above
  # Except in the case of odd number of cases it does the middle group alone
  # Then does the expanding pairs going up
  # Probably less efficient? But should test it
  
  num_elements = len(l)
  group_size = num_elements / num_groups

  moves = []

  high_low = num_groups // 2 * group_size
  high_high = high_low + group_size
  if num_groups % 2 == 1:
    low_high = high_high
    low_low = high_low
  else:
    low_high = high_low
    low_low = low_high - group_size
  
  while l:
    for _ in range(len(l)):
      if high_low <= l[0] < high_high:
        pb(l, r, moves)
      elif low_low <= l[0] < low_high:
        pb(l, r, moves)
        rb(l, r, moves)
      else:
        ra(l, r, moves)
    low_high = low_low
    low_low -= group_size
    high_low = high_high
    high_high += group_size
  
  return moves

def contains_value_in_range(list, lower_bound, upper_bound):
  # Checks to see if a list contains a number between the range
  for elem in list:
    if lower_bound <= elem <= upper_bound:
      return True
  return False

def forward_is_closer(list, lower_bound, upper_bound):
  if lower_bound <= list[0] <= upper_bound:
    return True
  i = 1
  while i < len(list) // 2:
    if lower_bound <= list[i] <= upper_bound:
      return True
    if lower_bound <= list[-i] <= upper_bound:
      return False
    i += 1

  # Hmm, there is no number of this value in the search
  return True


def split_into_buckets_double_with_reverse_rotate(l, r, num_groups):
  # Same as above, except it is willing to reverse move to search for the numbers

  num_elements = len(l)
  group_size = num_elements / num_groups

  moves = []

  low_high = num_groups // 2 * group_size
  high_low = low_high
  low_low = low_high - group_size
  high_high = high_low + group_size

  while l:
    while contains_value_in_range(l, low_low, high_high):
      if high_low <= l[0] <= high_high:
        pb(l, r, moves)
      elif low_low <= l[0] <= low_high:
        pb(l, r, moves)
        rb(l, r, moves)
      else:
        if forward_is_closer(l, low_low, high_high):
          ra(l, r, moves)
        else:
          rra(l, r, moves)
    low_high = low_low
    low_low -= group_size
    high_low = high_high
    high_high += group_size
    # print(l)
    # print(f"ll: {low_low} lh: {low_high} hl: {high_low} hh: {high_high}")
  return moves

def pre_split_into_buckets(l, r, num_pre_groups, num_groups):
  num_elements = len(l)
  group_size = num_elements / num_groups
  groups_per_pre_group = num_groups // num_pre_groups

  moves = []

  high_cut = len(l) - group_size * groups_per_pre_group // 2
  low_cut = group_size * groups_per_pre_group // 2

  while l:
    for _ in range(len(l)):
      if l[0] <= low_cut or l[0] >= high_cut:
        pb(l, r, moves)
      else:
        ra(l, r, moves)
    high_cut -= group_size * groups_per_pre_group // 2
    low_cut += group_size * groups_per_pre_group // 2

  return moves


def find_distance_from(stack, val):
  # Searches for the closest way to get to a searched for number
  
  distance = 0
  while stack[distance] != val:
    distance += 1

  if len(stack) - distance < distance:
    # distance = (len(stack) - distance) * - 1
    distance = distance - len(stack)

  return distance
    

def selection_sort_back(l, r):
  # Does an selection sort to pull back from r to l

  moves = []

  current_target = len(r) - 1
  while r:
    distance = find_distance_from(r, current_target)
    while distance > 0:
      rb(l, r, moves)
      distance -= 1
    while distance < 0:
      rrb(l, r, moves)
      distance += 1
    pa(l, r, moves)
    current_target -= 1

  return moves

def push_back_val(l, r, val):

  moves = []
  distance = find_distance_from(r, val)
  while distance > 0:
    rb(l, r, moves)
    distance -= 1
  while distance < 0:
    rrb(l, r, moves)
    distance += 1
  pa(l, r, moves)
  return moves

def push_back_all(l, r):
  moves = []
  while r:
    pa(l, r, moves)
  return moves

def selection_sort_back_2(l, r):
  # Does the same as regular selection sort but it is willing to pull out the second lowest and do a swap op instead

  moves = []
  
  current_target = len(r) - 1
  while r:
    next_target = current_target - 1
    if next_target < 0:
      next_target = 0
    distance_target = find_distance_from(r, current_target)
    distance_next_target = find_distance_from(r, next_target)

    if abs(distance_target) < abs(distance_next_target) or current_target == next_target:
      moves.extend(push_back_val(l, r, current_target))
      current_target -= 1
    else:
      moves.extend(push_back_val(l, r, next_target))
      moves.extend(push_back_val(l, r, current_target))
      sa(l, r, moves)
      current_target -= 2

  return moves

# max = len(l)
# div = 2
# while l:
#     for i in range(len(l)):
#         if l[0] >= max // div:
#             pb(l, r, m)
#         else:
#             ra(l, r, m)
#     div *= 2


# print("----------")
# print(l)
# print(r)
# print(f"Is sorted: {is_sorted(l, r)}")
# print("----------")

# print(len(m))



# print(" ".join(m))


# if __name__ == "__main__":

# test_100 = "97 92 84 98 19 43 50 75 59 37 90 39 79 44 49 83 45 89 65 53 47 38 71 42 8 7 5 91 82 48 96 6 77 24 31 36 18 33 81 28 32 23 85 25 2 88 11 55 16 93 64 20 95 72 30 46 26 57 4 73 60 70 78 22 29 80 86 94 14 35 63 34 56 58 15 21 67 52 10 12 66 76 62 9 99 17 74 69 54 41 3 51 61 87 1 100 27 13 40 68"
# test_100_1 = "961 888 186 222 830 941 563 93 258 101 901 824 103 790 415 716 299 336 230 940 564 76 293 262 784 975 621 62 495 865 746 235 930 860 34 50 386 118 33 446 910 801 754 141 524 568 140 350 308 542 367 874 772 872 188 767 873 110 448 592 842 417 30 960 764 314 41 778 507 25 890 279 292 400 964 348 534 161 527 984 566 690 773 706 502 691 978 9 980 168 106 920 822 115 535 796 533 870 859 766"
# test_100_2 = "916 523 953 801 841 565 797 314 784 531 787 211 754 581 434 818 933 1000 786 636 282 300 42 51 891 168 974 864 357 952 125 998 115 987 485 720 746 306 445 677 137 152 76 513 262 296 346 116 623 627 699 386 629 25 781 91 273 795 455 668 594 503 988 77 834 755 33 294 121 548 756 492 153 963 379 310 147 249 931 338 220 238 401 207 901 2 920 195 119 904 367 334 819 897 508 537 738 406 63 885"

# test_500_1 = "3745 2919 4867 688 2165 2555 2503 720 2620 2143 2112 1389 563 4334 2156 2672 262 2902 3225 3957 4718 969 459 4520 1722 2477 3159 3594 3462 4628 626 1374 4784 1799 773 1220 834 4122 4639 909 1895 4873 3675 3940 4497 4865 562 2113 4694 2330 2461 3966 1177 3054 1817 1522 4100 4017 1801 897 3513 1936 101 4025 2422 2764 3504 1203 2095 3060 3945 1368 2201 3134 2196 4649 4876 1851 1526 3900 829 442 2814 4173 2451 3686 2909 4007 2117 1495 429 661 730 129 282 2698 2261 3169 3624 114 4368 4714 4528 1025 3902 4254 1552 440 4821 3311 1765 567 2046 2375 4523 933 4918 986 3958 2563 3209 3243 4915 1984 4555 1188 156 464 2778 2336 783 4903 4541 1292 835 3318 3925 2376 684 3019 4156 2028 134 378 4238 4490 4277 2351 1627 224 4158 3780 2962 1306 1348 3272 4755 1577 79 3722 3336 1068 159 3255 989 3772 735 3094 1392 709 841 666 3221 3535 4799 939 4871 3162 4421 4636 423 3117 4381 3456 5000 329 2706 1194 3894 3076 3127 2191 4205 4389 1660 4522 78 842 1594 3044 1943 71 2120 1192 1543 4654 971 1814 1679 4475 3705 4285 4510 2521 1106 1011 1894 4517 972 2 46 4614 2262 3558 1413 4034 3874 2770 1248 819 586 3274 2240 1752 2848 3834 4778 951 456 2449 3147 4720 3276 1710 2572 627 1614 3314 977 1707 3873 4364 4745 4000 2307 1309 3502 1980 3034 108 2070 4233 393 2568 386 2409 3026 1749 3476 696 1313 4150 1310 2393 481 1939 931 817 1014 2578 2601 4646 3770 3365 3301 4967 2617 2443 1743 3593 4208 154 2928 2398 289 2787 832 818 3600 306 398 397 953 480 4942 4458 1149 2910 1007 3104 4769 4762 4240 4610 2362 3618 3846 2091 514 3428 660 991 1585 2068 4752 2716 3727 191 4331 4663 2224 220 416 1319 2610 2132 2317 207 1504 605 4648 4363 664 4710 164 2616 1642 365 4388 3676 3253 4063 3238 61 261 142 3655 1639 3302 3191 1339 4933 2854 1632 3804 831 833 2467 741 3832 1518 2627 2080 2498 4124 3079 3826 2507 1087 3597 4716 3406 996 531 690 2779 1896 4653 2164 615 2730 3173 1304 1607 270 893 4448 955 343 4031 2031 3021 2937 1449 2431 3030 4402 2984 1217 2060 3606 200 69 66 2200 981 3170 1181 4192 4480 2071 1394 758 3242 3142 2107 1770 4038 4830 4676 2299 1564 2838 1729 1700 292 4272 3106 3128 1150 668 4642 273 1384 4925 90 2856 1215 568 3533 4072 4386 4703 3721 4675 921 646 542 4269 4615 1935 908 4634 31 2743 3419 3538 2509 2872 2008 1444 4054 4375 3397 3184 1727 2430 4768 541 1554 1165 3810 923 1191 2411 3773 2871 3152 50 3824 4242 3498 4170 3999 853 3621 4553 3315 4226 2440"
# test_500_2 = "2845 613 4107 1250 958 1143 4672 3717 1431 4848 3228 3218 672 744 3790 4211 2738 3373 3893 2360 2961 3011 3422 2627 4889 2783 4719 75 3330 1681 3309 2590 3380 1573 2372 157 1215 683 262 2059 2770 540 2867 2106 2774 521 2644 4338 2111 1123 3573 4778 2746 397 2129 2972 2457 4201 1902 2402 3259 985 155 1508 1501 2031 1781 652 3005 4293 1798 589 3629 1042 4990 4281 1035 742 2292 4189 1724 105 1322 718 1088 4498 4491 1429 3102 4399 4934 4412 4442 4633 3968 1880 1400 1207 4560 4575 4845 3159 2077 1857 4066 1712 2650 3510 1895 4144 3924 3018 4451 3369 1472 1499 58 4339 1806 4239 1500 2923 2355 1197 1928 2626 1672 2195 1647 1353 1480 6 2869 2293 746 3491 3830 2863 211 1621 1690 1227 4875 4245 2968 4360 4059 923 4568 1343 2381 1072 318 1856 4847 584 3912 822 576 2063 4741 4974 4899 2548 1583 2179 3096 3725 2153 4048 2078 2652 27 3141 3700 2490 3869 382 1284 4776 604 3175 265 3028 2238 4 4817 524 2532 4748 592 1260 2128 246 3364 1016 3861 4897 2544 401 3920 3899 2551 2074 4570 2991 287 2219 3282 7 4536 3569 3741 4699 4506 4374 2924 517 4571 2899 3595 3063 1884 462 3871 2861 1218 4348 2243 3099 4501 882 1109 3713 2096 4731 2367 4287 1471 3553 89 4446 3934 3449 2697 2456 4235 3701 2599 3416 2325 344 4054 2435 3122 42 3047 4537 1038 3635 3017 1461 4358 2440 3429 700 3994 1451 3486 3396 2761 4108 3264 3167 181 373 3081 4242 4096 1414 774 4052 2178 301 681 4416 1309 1999 762 563 1 4551 2520 3194 3184 3927 335 1596 472 2591 2453 2762 3845 2460 4343 85 138 602 598 767 3490 3859 4810 1225 225 666 2656 3831 4444 993 1669 176 3337 2035 4684 1312 4081 4602 520 2839 3119 4236 3966 4923 1989 811 3071 1530 4091 1660 1426 926 4756 4147 2959 3326 2141 4006 3146 2776 1263 3664 3484 1195 4333 2239 477 1148 4911 193 4528 999 3245 156 3469 4418 3268 4799 3564 192 2595 1034 3300 2072 3492 4637 358 4806 3811 2791 1137 1556 1976 239 4485 2503 1448 2622 1723 4621 3302 46 1266 3080 709 2352 2598 266 2204 3972 3875 1821 2329 3576 2033 586 391 4470 515 544 1525 4377 2046 2496 3579 1202 3086 1722 4888 3067 427 3503 3287 2725 2163 777 2237 4202 4356 2708 4254 3049 3719 3804 3556 2840 4838 1529 163 1753 529 847 2155 484 1728 4041 4342 11 4331 2935 1854 4184 3843 3537 4812 4696 506 2931 3295 4818 4127 556 4437 1587 2190 4311 2410 590 342 2348 3987 3258 1847 2158 859 3748 380 2461 2597 1808 2894 4775 4646 321 4710 673 303 2716 4499 2815 3695 4655 697 3473 1297 177 4240 3896 833 2264"

# test_3 = "0 2 1"
# test_5 = "1 4 2 3 0"

# Debug with test strings
# test = test_5
# nums = list(map(int, test.split(" ")))

# # Take arg strings
nums = list(map(int, sys.argv[1:]))


sorted_nums = sorted(nums)
number_lookup = {}
for i, num in enumerate(sorted_nums):
    number_lookup[num] = i

l = deque()
for num in nums:
    l.append(number_lookup[num])
r = deque()
m = []

if len(l) == 0:
  pass
elif len(l) == 3:
  sort_3_elements(l, r, m, l)
elif len(l) == 4:
  m.extend(sort_4_elements(l, r))
elif len(l) == 5:
  m.extend(sort_5_elements(l, r,))
elif len(l) < 50:
  m.extend(double_radix_sort(l, r))
elif len(l) < 150:
  # Solution to 100
  m.extend(split_into_buckets_double(l, r, 8))
  m.extend(selection_sort_back_2(l, r))
elif len(l) < 600:
  # Solution to 500
  m.extend(pre_split_into_buckets(l, r, 4, 32))
  m.extend(push_back_all(l, r))
  m.extend(split_into_buckets_double_with_reverse_rotate(l, r, 32))
  m.extend(selection_sort_back_2(l, r))
else:
  m.extend(double_radix_sort(l, r))

# m = double_radix_sort(l, r)

#TOWER OF HANOI SORT

for action in m:
  print(action)