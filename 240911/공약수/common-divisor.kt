import java.math.BigInteger
fun main()
{
    val n=readLine()!!.toInt()
    val nums=readLine()!!.split(" ").map{it.toInt()}
    val s=nums.size
    var temp=nums[0]
    for(i in 0..s-2) {
        temp=temp.toBigInteger().gcd(nums[i+1].toBigInteger()).toInt()
    }
    for(i in 1..temp)
    {
        if(temp%i==0)println(i)
    }
}