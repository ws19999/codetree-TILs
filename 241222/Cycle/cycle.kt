fun main()
{
    val (N,P)=readLine()!!.split(" ").map{it.toInt()}
    var num=N
    var pos=1
    val keys:MutableMap<Int,Int> = mutableMapOf()
    while(keys[num]==null){
        keys[num]=pos++
        num=(num*N)%P
    }
    print("${pos-keys[num]!!}")
}