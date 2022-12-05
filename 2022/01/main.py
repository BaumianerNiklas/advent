from functools import reduce


def get_food_lists() -> list[list[int]]:
	food_lists: list[list[int]] = []

	with open("./input.txt", encoding="utf8") as f:
		lines = f.read().split("\n")
		current_list = []

		for line in lines:
			if line == "":
				food_lists.append(current_list)
				current_list = []
				continue

			current_list.append(int(line))

	return food_lists


def sum_calories(food_lists: list[list[int]]) -> list[int]:
	calory_list = []
	for list in food_lists:
		calory_list.append(reduce(lambda curr, acc: curr + acc, list))

	return calory_list


def part1():
	return max(sum_calories(get_food_lists()))


def part2():
	food_lists = get_food_lists()
	calory_list = sum_calories(food_lists)
	calory_list.sort()

	return sum(calory_list[-3:])


if __name__ == "__main__":
	print(f"PART ONE: {part1()}")
	print(f"PART TWO: {part2()}")
