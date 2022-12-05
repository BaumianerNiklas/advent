assignments = []


def range_from_assignment(assignment):
	split = assignment.split("-")
	return range(int(split[0]), int(split[1]) + 1)


with open("./input.txt") as f:
	lines = f.read().split("\n")

	for line in lines:
		range1, range2 = line.split(",")
		range1 = range_from_assignment(range1)
		range2 = range_from_assignment(range2)
		assignments.append((range1, range2))

count1 = 0
count2 = 0
for ass in assignments:
	range1, range2 = ass
	set1 = set(range1)
	set2 = set(range2)

	if len(set1 - set2) == 0 or len(set2 - set1) == 0:
		count1 += 1

	if len(set1 & set2) > 0:
		count2 += 1

print(count1)
print(count2)
