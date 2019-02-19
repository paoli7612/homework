<div class="w3-panel">
	<a href="index.php">
		<button type="button" class="w3-button w3-card-4 w3-white w3-round-xlarge">Ricomincia</button>
	</a>
</div>

<div class="w3-display-container">
	<div class="w3-panel w3-display-<?php echo $_POST['align']; ?>">
		<?php for ($i=0; $i<$_POST['number']; $i++): ?>
			<div class="w3-panel w3-white w3-border w3-center w3-card-4 w3-round-xlarge">
				<h1> <?php echo $i+10; ?> </h1>
			</div>
		<?php endfor; ?>
	</div>
</div>
