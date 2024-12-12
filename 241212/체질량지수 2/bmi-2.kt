fun main(){
    val(height, weight)=readLine()!!.split(" ").map{it.toInt()}
    val BMI=(weight.toDouble()/((height.toDouble()/100.0)*(height.toDouble()/100.0))).toInt()
    println(BMI)
    if(BMI>=25)print("Obesity")
}