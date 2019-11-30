
fun main() {
	var n = readLine()!!.toInt()
	var s = readLine()!!.toString()

	val map = mutableMapOf<String,Int>()

	var i = 0

	while( i < n-1 ) {
		var key = s[i] + "" + s[i+1]
		if (map[ key ] == null) {
			map[ key ] = 1
		} else {
			map[ key ] = map[ key ]!! + 1
		}
		i++;
	}
	
	var ans = 0;
	var solution = ""
	for(k in map) {
		var (a,b) = k
		if ( b > ans ) {
			solution = a
			ans = b
		}
	}
	println(solution)
}