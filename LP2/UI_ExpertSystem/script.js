function checkDisease(){

    let fever =
    document.getElementById("fever").checked;

    let cough =
    document.getElementById("cough").checked;

    let headache =
    document.getElementById("headache").checked;

    let stomach =
    document.getElementById("stomach").checked;

    let bodyPain =
    document.getElementById("bodyPain").checked;

    let cold =
    document.getElementById("cold").checked;

    let vomiting =
    document.getElementById("vomiting").checked;

    let tiredness =
    document.getElementById("tiredness").checked;

    let result =
    document.getElementById("result");

    // Rule-Based Expert System

    if(fever && cough && cold){

        result.innerHTML =
        "<h3>Possible Disease : Common Flu</h3>" +
        "<p>Advice : Take rest, warm water and medicines.</p>";
    }

    else if(fever && headache && bodyPain){

        result.innerHTML =
        "<h3>Possible Disease : Viral Fever</h3>" +
        "<p>Advice : Consult a doctor immediately.</p>";
    }

    else if(stomach && vomiting){

        result.innerHTML =
        "<h3>Possible Disease : Food Poisoning</h3>" +
        "<p>Advice : Drink ORS and avoid outside food.</p>";
    }

    else if(cough && tiredness){

        result.innerHTML =
        "<h3>Possible Disease : Throat Infection</h3>" +
        "<p>Advice : Avoid cold drinks and take steam.</p>";
    }

    else if(fever && tiredness && bodyPain){

        result.innerHTML =
        "<h3>Possible Disease : Dengue Symptoms</h3>" +
        "<p>Advice : Medical test recommended.</p>";
    }

    else{

        result.innerHTML =
        "<h3>No Major Illness Detected</h3>" +
        "<p>Maintain healthy lifestyle and diet.</p>";
    }
}