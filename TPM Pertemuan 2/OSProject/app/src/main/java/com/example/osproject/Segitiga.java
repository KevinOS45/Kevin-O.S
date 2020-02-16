package com.example.osproject;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class Segitiga extends AppCompatActivity {
    private TextView tv_hasil;
    private EditText alas , tinggi;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_segitiga);
    }

    public void OnShowSegitiga(View view){
        try {
            tv_hasil = findViewById(R.id.tv_hasil);
            alas = findViewById(R.id.et_alasSegitiga);
            tinggi = findViewById(R.id.et_tinggiSegitiga);

            float sumsegitiga = (Float.parseFloat(String.valueOf(alas.getText())) * Float.parseFloat(String.valueOf(tinggi.getText())))/2;

            tv_hasil.setText(String.valueOf(sumsegitiga));

        }catch(NumberFormatException nfe){
            Toast.makeText(getApplicationContext(),"Setidaknya ISi Dengan Angka!!!", Toast.LENGTH_SHORT).show();
        }
    }
}
