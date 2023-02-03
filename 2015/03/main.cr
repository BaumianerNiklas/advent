alias Position = {x: Int32, y: Int32}

map = Hash(Position, Int32).new
pos = { x: 0, y: 0 }
map[pos] = 1

robo_pos = { x: 0, y: 0 }
robo = false

def move(char : String, pos : Position, map : Hash(Position, Int32))
	new_x = pos[:x]
	new_y = pos[:y]

	case char
	when "v"
		new_y -= 1
	when "^"
		new_y += 1
	when ">"
		new_x += 1
	when "<"
		new_x -= 1
	end

	{ x: new_x, y: new_y }
end

input = File.read("input.txt")

input.split "" do |char|
	if robo
		robo_pos = move(char, robo_pos, map)
		map[robo_pos] = map.fetch(robo_pos, 0) + 1
	else 
		pos = move(char, pos, map)
		map[pos] = map.fetch(pos, 0) + 1
	end

	robo = !robo
end

puts map.values.count { |val|
	val >= 1
}

