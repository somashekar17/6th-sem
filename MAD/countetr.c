activity_main.xml:
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout
xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:app="http://schemas.android.com/apk/res-auto"
 xmlns:tools="http://schemas.android.com/tools"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 tools:context=".MainActivity">
 <Button
 android:id="@+id/stopBtn"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:text="@string/stop"
 app:layout_constraintBottom_toBottomOf="parent"
 app:layout_constraintEnd_toEndOf="parent"
 app:layout_constraintStart_toStartOf="parent"
 app:layout_constraintTop_toTopOf="parent"
 app:layout_constraintVertical_bias="0.585" />
 <Button
 android:id="@+id/startBtn"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:text="@string/start"
 app:layout_constraintBottom_toBottomOf="parent"
 app:layout_constraintEnd_toEndOf="parent"
 app:layout_constraintStart_toStartOf="parent"
 app:layout_constraintTop_toTopOf="parent" />

<TextView
 android:id="@+id/viewNumber"
 android:layout_width="114dp"
 android:layout_height="46dp"
 android:text="TextView"
 android:textAlignment="center"
 android:textSize="24sp"
 app:layout_constraintBottom_toBottomOf="parent"
 app:layout_constraintEnd_toEndOf="parent"
 app:layout_constraintHorizontal_bias="0.498"
 app:layout_constraintStart_toStartOf="parent"
 app:layout_constraintTop_toTopOf="parent"
 app:layout_constraintVertical_bias="0.41" />
</androidx.constraintlayout.widget.ConstraintLayout>



strings.xml:
<resources>
 <string name="app_name">Counter</string>
 <string name="start">Start</string>
 <string name="stop">Stop</string>
</resources>
________________


>MainActivity.kt:
package com.example.counter
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.CountDownTimer
import kotlinx.android.synthetic.main.activity_main.*
class MainActivity : AppCompatActivity() {
 private val timer = MyCounter(10000000, 1000)
 var countervalue : Int = 1
 override fun onCreate(savedInstanceState: Bundle?) {
 super.onCreate(savedInstanceState)
 setContentView(R.layout.activity_main)
 startBtn.setOnClickListener {
 timer.start()
 startBtn.isEnabled = false
 }

stopBtn.setOnClickListener {
 timer.cancel()
 startBtn.isEnabled = true
 }
 }
 inner class MyCounter(millisInFuture: Long, countDownInterval: Long) :
CountDownTimer(millisInFuture, countDownInterval) {
 override fun onFinish() {
 }
 override fun onTick(millisUntilFinished: Long) {
 countervalue++
 viewNumber.text = (countervalue).toString()
 }
 }
}
