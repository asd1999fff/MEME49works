const express = require('express');
const app = express();
app.listen(8181);
const fs = require('fs');
const csvToJson = require('convert-csv-to-json');

app.use((req,res,next)=>{
    json=csvToJson.fieldDelimiter(',').getJsonFromCsv("./employee.csv");
    res.setHeader('Access-Control-Allow-Origin','*');
    res.setHeader('Content-Type','text/html; charset=UTF-8');
    next();
});

app.get('/Addnewdata',(req ,res) =>{
    let data = 'Name:'+req.query.name+","+"jobs:"+req.query.jobs+","+"habbit:"+req.query.habbit+","+"date:"+req.query.date+","+"age:"+req.query.age+","+"employeeno:"+req.query.employeeno+"\n";
    fs.appendFile('data.csv',data,(err) =>{
            if (err) throw err;
            console.log('appended!!');
        });
    res.end('saved!!!');
});


app.get('/Delete',(req,res) =>{
    fs.readFile('data.csv','utf8',(err,data)=>{
        console.err('Error reading File',err);
        return;
    });
    
    //const jsonData = JSON.parse(data);

    //const 

})