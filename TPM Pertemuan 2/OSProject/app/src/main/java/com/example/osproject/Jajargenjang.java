package com.example.osproject;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class Jajargenjang extends AppCompatActivity {
    private TextView tv_hasil;
    private EditText alas , tinggi;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_jajargenjang);
    }

    public void OnShowJajargenjang(View view){
        try {
            tv_hasil = findViewById(R.id.tv_hasil);
            alas = findViewById(R.id.et_alasJajar);
            tinggi = findViewById(R.id.et_tinggiJajar);

            float sumjajargenjang = Float.parseFloat(String.valueOf(alas.getText())) * Float.parseFloat(String.valueOf(tinggi.getText()));

            tv_hasil.setText(String.valueOf(sumjajargenjang));

        }catch(NumberFormatException nfe){
            Toast.makeText(getApplicationContext(),"Setidaknya mAsukkan Angka!!!", Toast.LENGTH_SHORT).show();
        }
    }
}
