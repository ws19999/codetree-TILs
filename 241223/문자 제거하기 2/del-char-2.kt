fun main(){
    var (a,n)=readLine()!!.split(" ")
    val s=n.toInt()
    repeat(s){
        val k=readLine()!!.toInt()
        if(k<=a.length){
            a=a.substring(0,k-1)+a.substring(k)
            println(a)
        }
    }
}