
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun nextLongs() = readLine()!!.split(" ").map { it.toLong() } // list of longs

fun main() {
	var (a, b) = readInts()
	val arr = readInts().sorted()

	if ( b == 0 ) {
		if ( arr[0] == 1 ) {
			println(-1)
		} else println(1)
		return
	}
	if( a == b ) {
		println(arr[b-1])
		return
	}

	if ( arr[b-1] == arr[b+1-1] ) {
		println(-1) 
	} else {
		println(arr[b-1])
	}
}