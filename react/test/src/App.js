import './App.css';
import React, { useState, useEffect } from 'react';
import './MOKpokemon.db/pokemon';







function App() {
const [list, setList] = useState();

useEffect(()=> {
  fetch('')
  const json = response.json();
  console.log(json)
}, [])

}

export default App;
