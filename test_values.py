import random

max_val = 1000;
print(" ".join(map(str, sorted(range(0, max_val), key=lambda k: random.random()))))

# Valgrind test string
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./push_swap `python3 ~/Desktop/42school/42-push_swap/test_values.py`