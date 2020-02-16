package com.example.osproject;


import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    public void OnShowSegitiga (View view){
        Intent intent = new Intent(this,Segitiga.class);
        startActivity(intent);
    }

    public void OnShowJajargenjang (View view){
        Intent intent = new Intent(this, Jajargenjang.class);
        startActivity(intent);
    }

}
