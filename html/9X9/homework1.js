document.write(`<table>`);
for(let j = 2 ; j < 10 ; j++){ 
    document.write(`<tr>`)
    document.write(`<td>`)
  for (let i = 1; i < 10; i++)
  {
    document.write(`${j}*${i}=${i * j}</br>`)
  }
    document.write(`</td>`)
    document.write(`</tr>`)
}
document.write(`</table>`)