
fun main() {
	var (n, k) = readLine()!!.split(" ").map { it.toInt() }

	while( k > 0 ) {
		if ( n%10 != 0 ) {
			n -= 1;
		} else {
			n /= 10;
		}
		k -=1;
	}
	println(n)
}
