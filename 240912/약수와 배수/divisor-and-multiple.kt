fun main()
{
    val n=readLine()!!.toInt()
    val nums=readLine()!!.trim().split(" ").map{it.toInt()}
    val k=readLine()!!.toInt()
    var 약수=0
    var 배수=0
    for(i in nums)
    {
        if(k%i==0)약수+=i
        if(i%k==0)배수+=i
    }
    println(약수)
    println(배수)
}