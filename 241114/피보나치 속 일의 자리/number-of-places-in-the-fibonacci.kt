fun main()
{
    val n=readLine()!!.toInt()
    var (a,b)=readLine()!!.trim().split(" ").map{it.toInt()}
    var arr=IntArray(n){0}
    arr[0]=a
    arr[1]=b
    for(i in 0..n-1)
    {
        if(i>1)arr[i]=(arr[i-2]+arr[i-1])%10
        print("${arr[i]} ")
    }
}